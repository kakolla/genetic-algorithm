import { useState } from 'react'
import './App.css'


// Web socket function
function run(setWs: React.Dispatch<React.SetStateAction<WebSocket | null>>, setMsg: React.Dispatch<React.SetStateAction<string | undefined>>) {
  console.log("starting");
  const socket: WebSocket = new WebSocket("ws://localhost:5000");
  setWs(socket);

  // first send hyperparameters for the C++ program
  const pop_size: number = parseFloat((document.getElementById("pop_size") as HTMLInputElement).value) || 200;
  const select_rate: number = parseFloat((document.getElementById("select_rate") as HTMLInputElement).value) || 0.10;
  const mut_rate: number = parseFloat((document.getElementById("mut_rate") as HTMLInputElement).value) || 0.05;
  console.log(pop_size);
  console.log(select_rate);
  console.log(mut_rate);
  const hyperparameters = [pop_size, select_rate, mut_rate];


  socket.onopen = () => {
    console.log("Connected to WebSocket server");
    socket.send(JSON.stringify(hyperparameters)); // Send message to start C++ process
    // socket.send("Start");
  };

  // receiving msgs
  socket.onmessage = (event) => {
    console.log("Received:", event.data);
    setMsg(event.data); // Store received messages
  };

  socket.onclose = () => {
    console.log("WebSocket connection closed");
    socket.close();
  };


  // return () => socket.close(); // Clean up connection on unmount

}

function App() {
  const [msg, setMsg] = useState<string>();
  const [ws, setWs] = useState<WebSocket | null>(null);


  return (
    <div>
      <h1>Genetic Algorithm</h1>
      <div>
        <h4>Population size</h4>
        <input type="number" id="pop_size" defaultValue={200}></input>
        <h4>Selection rate</h4>
        <input type="number" id="select_rate" defaultValue={0.1}></input>
        <h4>Mutation rate</h4>
        <input type="number" id="mut_rate" defaultValue={0.05}></input>
      </div>
      <br />
      <button onClick={() => run(setWs, setMsg)}>Run Algorithm</button>
      <h2>{msg}</h2>
    </div>
  )
}

export default App;

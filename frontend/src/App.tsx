import { useEffect, useState } from 'react'
import './App.css'

function run(setWs: React.Dispatch<React.SetStateAction<WebSocket | null>>, setMsg: React.Dispatch<React.SetStateAction<string | undefined>>) {
  console.log("starting");
  const socket: WebSocket = new WebSocket("ws://localhost:5000");
  setWs(socket);

  socket.onopen = () => {
    console.log("Connected to WebSocket server");
    socket.send("Start algorithm"); // Send message to start C++ process
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

  // useEffect(() => {

  // }, []);

  return (
    <div>
      <h1>Genetic Algorithm</h1>
      <button onClick={() => run(setWs, setMsg)}>Run Algorithm</button>
      <h2>{msg}</h2>
      {/* <ul>
        {msgs.map((msg, i) => (
          <li key={i}>{msg}</li>
        ))}
      </ul> */}
    </div>
  )
}

export default App;

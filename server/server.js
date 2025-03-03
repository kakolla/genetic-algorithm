const { spawn } = require('child_process');
const WebSocket = require('ws');


// create web socket server
const wss = new WebSocket.Server({port : 5000});

wss.on('connection', (ws) => {
    console.log('client connected');

    ws.on('message', (msg) => {
        console.log('received: ', msg);

        // first initialize parameters
        const receivedHyperparameters = JSON.parse(msg);
        const file_name = "target.txt";
        console.log("using these parameters: ", receivedHyperparameters)
        let pop_size;
        let select_rate;
        let mut_rate;

        [pop_size, select_rate, mut_rate] = receivedHyperparameters;

        // run the c++ algo
        const cppProcess = spawn('../program.exe', [file_name, pop_size, select_rate, mut_rate]);
        // const cppProcess = spawn('../program.exe', ["target.txt", 200, 0.1, 0.05]);

        // send each iterations output from stdout
        cppProcess.stdout.on('data', (data) => {
            ws.send(data.toString());
        });

        // error msg
        cppProcess.stderr.on('data', (data) => {
            console.error('Error: ${data}');
        });

        cppProcess.on('close', (code) => {
            console.log('C++ process exited with exit code: ', code);
        });

        ws.on('close', () => {
            console.log('client disconnected');
        })

    })
})
const { spawn } = require('child_process');
const WebSocket = require('ws');


// create web socket server
const wss = new WebSocket.Server({port : 5000});

wss.on('connection', (ws) => {
    console.log('client connected');

    ws.on('message', (msg) => {
        console.log('received: ', msg);

        // run the c++ algo
        const cppProcess = spawn('../program.exe', ["target.txt", 200, 0.1, 0.05]);

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
            // ws.send('__DONE__');
        });

        ws.on('close', () => {
            console.log('client disconnected');
        })

    })
})
const http = require('http');


// create server
const server = http.createServer((req, res) => {
    res.writeHead(200, {'Content-Type': 'text/plain'});

    // send a response
    res.end("Hello from the server");
})


// set server on port 
server.listen(5000, () => {
    console.log("running on 5000");
})
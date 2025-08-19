# Minitalk

## About the Project

Minitalk is a 42 project where the challenge is to create simple communication between two processes using Unix signals (`SIGUSR1` and `SIGUSR2`).

The goal is to send text messages from a client to a server by encoding characters bit by bit via signals, ensuring reliable reception.

This was my first project involving inter-process communication and signal handling, giving me solid insights into low-level IPC in C.

---

## What I Learned

- Using Unix signals for IPC (`kill`, `sigaction`).
- Encoding and decoding characters by transmitting bits.
- Synchronization and flow control using signals.
- Handling buffers and strings in C.
- Error handling and communication robustness.

---

## Features Implemented

- Server that receives signals and reconstructs messages.
- Client that sends messages bit-by-bit encoded in signals.
- Acknowledgement of message reception by the server.
- Support for multiple sequential messages.
- Modular and clean code organization.

---

## Compatibility

Developed and tested on Linux (Ubuntu), compiled with GCC, using only standard 42-allowed libraries.

---

## How to Use

Clone the repository and compile:

```bash
git clone https://github.com/YourUsername/minitalk.git
cd minitalk
make
```
Run the server (it will print its PID):
```bash
./server
```
In another terminal, send a message with the client, passing the server’s PID and the message:
```bash
./client <SERVER_PID> "Your message here"
```
Example
```bash
$ ./server
Server PID: 1234

$ ./client 1234 "Hello, minitalk!"
Hello, minitalk!
```
Future Improvements

- Support multiple simultaneous clients.
- Implement more robust acknowledgements and retransmissions.
- Add automated testing.
- Improve support for longer messages.

Final Thoughts

Minitalk was a milestone in learning low-level communication and process synchronization. Highly recommended if you want to understand signals and IPC hands-on!

## Contact
Feel free to reach out:

[Github](https://github.com/PedroLouzada)

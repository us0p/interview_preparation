# Node.js Technical Questions

## What is Node.js?
Node.js is a JavaScript runtime which uses the V8 engine to
execute JavaScript otside the browser. It uses an event-driven, 
non-blocking I/O model that makes it lightweight and efficient.

## What is REPL in Node.js?
Stads for Read-Eval-Print-Loop. It is an interactive shell that allows you 
to execute JavaScript code and view the output immediately.

## What is the difference between Node.js and JavaScript?
JavaScript is the programming language, Node.js is the JavaScript runtime 
which executes JavaScript scripts outside the browser.

## What is Event Loop in Node.js?
The event loop is a single-threaded loop responsible for handling all 
asynchronous tasks in Node.js.

It continuously checks for events and executes associated callbacks, 
allowing Node.js to handle asynchronous tasks efficiently.

Its non-blocking I/O model ensures that it can process multiple operations 
simultaneously without waiting for one to complete before moving on to the 
next.

## What is the difference between Node.js and AJAX?
Node.js is a server-side runtime for JavaScript, while AJAX is a 
client-side technique for asynchronous communication with the server.

## What are modules in Node.js?
Modules are reusable blocks of code that can be imported into other files.

They are used to encapsulate related code into a single unit of code that 
can be used in other parts of the program.

It allow us to split our code into multiple files and reuse it across 
multiple files.

## Difference between CommonJS and ESM?
CommonJS and ES Modules are two different module systems in JavaScript. 
CommonJS is the module system used in Node.js, while ES Module are the 
modules system used in browsers and TypeScript.

CommonJS modules are loaded syncrhonously. This means that the module is 
loaded and evaluated before the code using the module is executed.

ES Modules are loaded asynchronously. This means that the module is loaded 
and evaluated when the module is used.

## What is the `global` object in Node.js?
Is a global namespace object that contains all global variables, functions,
and objects. It is similar to the `window` object in the browser.

## What is the difference between `process.nextTIck()` and `setImmediate()`?
Both are used to schedule a callback to be executed in the next iteration 
of the event loop.

`process.nextTick()` executes the callback at the end of the current 
iteration.

`setImmediate()` executes the callback at the beginning of the next 
iteration of the event loop.

## What is `setInterval()`?
Is a global function that executes the provided callback at a fixed 
interval. It returns an interval ID on execution, which can be used to 
cancel the interval with the `clearInterval()` global function.

## What is `setTimeout()`?
Is a global function that executes the proved callback after the provided 
delay (which defaults to 1000ms). It returns a timeout ID which can be used
to cancel the execution using the `clearTimeout()` global function.

## What are Event Emitters in Node.js?
Event Emitters is a class that can be used to emit named events and 
register listeners for those events. It is used to handle asynchronous 
events in Node.js

## What is `npm`?
npm stands for Node Package Manager, It is used to install, update, and 
remove external packages. It's also used to manage project's dependencies.

## What is `npx`?
Is a tool that allows you to run Node.js packages without installing them. 
It is used to execute Node.js packages that are not installed globally.

## What is `process.cwd()`?
Returns the current working directory of the Node.js process.

## What is the difference between `process.cwd()` and `__dirname`?
`process.cwd()` returns the current working directory of the Node.js 
process, while `__dirname` returns the directory name of the current 
module.

## What is `__filename`?
Is a global variable that contains the absolute path of the current file.

## What is `process.argv`?
Is a variable that contains an array with the command-line parameters 
provided for the current Node.js process.
The first element is the path to the Node.js executable, the second is the 
path to the JavaScript file being executed, and the remaining elements are 
the command-line arguments.

## What is the purpose of `fs` module?
To enable access to the system's underlying file system. All file system 
operations have synchronous and asynchronous forms.

## What is the purpose of `path` module?
Used to perform operations on file and directory paths.

It provides methods for resolving, normalizing, and joining paths also 
extracting file and directory names.

## How to read a file in Node.js?
The simplest way would be to use the fs.readFile() function and provide the
file path. The function would read all the contents of the file into memory
and has both promise and callback apis.

## How to load environment variables from a `.env` file in Node.js?
The `dotenv` package is used to load environment variables from a `.env` 
file into `process.env`.

## How to access environment variables in Node.js?
Environment variables can be accessed using the `process.env` object. It's 
an object that contains all the environment variables defined in the 
current process.

## How to take user input from the command line in Node.js?
You can use the `readline` module. It provides an interface for reading 
data from a Readable stream one line at the time.

## How to create a web server in Node.js?
You can use the `http` module. The `http.createServer()` method is a 
constructor which yields an instance of HttpServer that can be used to 
serve HTTP request at a given port.

## What are streams in Node.js?
Objects that can be used to read or write data to a destination in a 
continuous manner. They are used to handle a large amount of data 
efficiently.

## What is the difference between `fork` and `spawn` methods of `child_process` module?
`fork` is used when you want to run another JavaScript file in a separate 
woker.

`spawn` is when you want to run a command in a separate process.

## What is the `os` module?
It provides methods for interacting with the operating system. It can be 
used to get information about the system, such as the hostname, platform, 
etc.

## Can you access the DOM in Node.js?
No, It's a server-side runtime for JavaScript, so it does not have access 
to the browser's DOM.

## What is clustering in Node.js?
Clustering is a technique used to distribute the load across multiple 
processes. It's used to improve the performance and scalability of Node.js 
applications.

## How can memory leaks happen in Node.js?
Memory leaks can happen due to the use of closures, circular references, 
and global variables.

## What is the order of priority of `process.nextTick`, `Promise`, `setTimeout`, and `setImmediate`?
1. `process.nextTick`: Highest priority, executed immediately after the 
    current event loop cycle, before any other I/O events or timers.
2. `Promise`: Executed in the microtask queue, after the current event loop
   cycle, but before the next one.
3. `setTimeout`: Executed in the timer queue, after the current event loop 
   cycle, with a minimum delay specified in milliseconds.
4. `setImmediate`: Executed in the check queue, but its order may vary 
   based on the system and load. It generally runs in the next iteration 
   of the event loop after I/O events.

## What is `process.exit()`?
Is a method used to exit the current process. It takes an optional exit 
code as an argument.

## How Node.js handle errors?
1. `try..catch` blocks.
2. error first callbacks.
3. rejected Promises.
4. emitted error events.

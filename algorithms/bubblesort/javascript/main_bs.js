let bubbleSort = require('./bubbleSort');
// import bubbleSort from './bubbleSort';
let rl = require('readline');
// import rl from 'readline';
// allow input through console
let prompt = rl.createInterface(process.stdin,
                                 process.stdout);

let array = [];
let flag = true;
console.log('Enter all the values. Press q to stop input');

function readInput() {
    prompt.question('>>', function(inp) {
        if (inp == 'q') {
            console.log('initial array: ', array);
            bubbleSort(array);
            console.log('final array: ', array);            

            return prompt.close();
        }

        array.push(Number(inp));
        readInput();
    });
}

readInput();

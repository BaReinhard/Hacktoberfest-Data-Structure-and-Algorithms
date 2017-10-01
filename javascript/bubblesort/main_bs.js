var bubbleSort = require('./bubbleSort');
var rl = require('readline');
// allow input through console
var prompt = rl.createInterface(process.stdin,
                                 process.stdout);

var array = [];
var flag = true;
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

'use strict';
export default function Stack(maxSize = null) {
    // Private variables
    let _data = [];
    let _top = -1;
    // Helper function to check if the stack is empty
    function _checkEmpty() {
        return _top === -1;
    }
    // Helper function to check if the stack is full
    function _checkFull() {
        return maxSize === null ? false : _top >= maxSize - 1;
    }
    // Error Helper Function to help display
    // when Stack is empty or full
    function throwError(message) {
        throw new Error(message);
        return true;
    }
    // Return Object
    let _Stack = {
        // Returns Top Data
        Top: () => {
            return _data[_top] !== undefined ? _data[_top] : null;
        },
        // Void, adds new Data
        Push: data => {
            !_checkFull() ? (_data[++_top] = data) : throwError('Stack is full');
        },
        // Void, removes Data
        Pop: () => {
            !_checkEmpty() ? _data.splice(_top--, 1) : throwError('Stack is empty');
        },
        // Void, logs Top Data
        Log: () => {
            console.log(this.Top());
        },
        // Void , logs all Data
        LogAll: () => {
            for (let i = 0; i < _top; i++) {
                console.log(_data[i]);
            }
        },
    };
    return _Stack;
}
// Test the Code

// let _ = data => {
//     console.log(data);
// };
// let stack = new Stack();

// try {
//     stack.Push(1);
//     _(stack.Top());
//     stack.Push(0b11);
//     _(stack.Top());
//     stack.Pop();
//     _(stack.Top());
// } catch (e) {
//     _(e.message);
// }


'use strict';
function Stack(maxSize = null) {
    function _checkEmpty() {
        return _top === -1;
    }
    function _checkFull() {
        return maxSize === null ? false : _top >= maxSize - 1;
    }
    function throwError(message) {
        throw new Error(message);
        return true;
    }
    // Private variables
    let _data = [];
    let _top = -1;

    // Return Object
    let _Stack = {
        // Returns Top Data
        Top: () => {
            return _data[_top] !== undefined ? _data[_top] : throwError('Stack is empty');
        },
        // Void, adds new Data
        Push: data => {
            if (!_checkFull()) {
                ++_top;
                _data[_top] = data;
            } else throwError('Stack is full');
            console.log(_data);
            return this;
        },
        // Void, removes Data
        Pop: () => {
            !_checkEmpty() ? (_data[_top] = undefined && --_top) : throwError('Stack is empty');
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

let _ = data => {
    console.log(data);
};
let stack = new Stack();

try {
    stack.Push(1);
    _(stack.Top());
    stack.Push('String');
    _(stack.Top());
    stack.Pop();
    _(stack.Top());
    stack.Pop();
    _(stack.Top());
} catch (e) {
    _(e.message);
}

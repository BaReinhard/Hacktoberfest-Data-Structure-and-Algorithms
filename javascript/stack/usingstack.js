import Stack from './stack';
import readline from 'readline';
(async function  RunMe(){
    let stack =  Stack();
    let input;
    const cin = readline.createInterface({
        input: process.stdin,
        output: process.stdout
      });
      
       cin.question('Test the stack class, type something it will output it backwards. Aka LIFO: ', (answer) => {
        input = answer;
        cin.close();
        for(let char of input){
            stack.Push(char);
        }
        while(stack.Top()!==null){
            console.log(stack.Top());
            stack.Pop();
        }
      });
      
      
})();


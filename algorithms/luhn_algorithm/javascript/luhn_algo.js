/**
 * This algorithm is used to validate credit card numbers, imei numbers.
 * This algorithm is also called as modulus 10 algorithm.
 */


function checkLump(validateNumber){
    let newNum = Array.from(validateNumber);
    for(let i=validateNumber.length-2; i>0; i-=2){
        let num = (parseInt(validateNumber[i])*2).toString();
        if(num.length ==2){
            num = (parseInt(num)-9).toString();
        }
        newNum[i] = num;
    }
    let sum = 0;
    for(let i=0;i<newNum.length; i++){
        sum +=parseInt(newNum[i]);
    }
    return sum%10 === 0;
}
/* checkLump returns true if the number is valid and false if the number is not valid
 */
let cardNumber = "1234567890"
console.log(checkLump(cardNumber));
const string = 'seconomicss432';
const cmp1 = 'be8'
const cmp2 = 'be82'

const smallre = new RegExp(('\w*' + cmp1+ '\w*'));
const smallre2 = new RegExp(('\w*' + cmp2 + '\w*'))
console.log(smallre)
var sa = smallre.exec(cmp2);
var sa2 = smallre2.exec(cmp1);
console.log(sa, sa2)

// const regex = new RegExp(('\w*' + cmp + '\w*'))
// const regex = /(\w*cmp\w*)/


// const regex = /([a-zA-Z0-9]*)?[\s-+]?([a-zA-Z0-9]*)?[\s-+]?([a-zA-Z0-9]*)?[\s-+]?([a-zA-Z0-9]*)?[\s-+]?([a-zA-Z0-9]*)?[\s-+]?([a-zA-Z0-9]*)?[\s-+]?([a-zA-Z0-9]*)?[\s-+]?([a-zA-Z0-9]*)?/
// const ans = regex.test(string);

// console.log(ans);


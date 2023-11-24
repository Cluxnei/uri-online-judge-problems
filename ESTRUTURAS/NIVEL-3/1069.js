const input = require('fs').readFileSync('/dev/stdin', 'utf8');
const lines = input.split('\n');
lines.shift();

while (lines.length) {
    const process = lines.shift().split('.').join('').split('');
    const open = process.filter(c => c === '<').length;
    const close = process.filter(c => c === '>').length;
    if (close > open) {
        console.log(open);
        continue;
    }
    if (open === close) {
        console.log(open);
        continue;
    }
    console.log(close);
}
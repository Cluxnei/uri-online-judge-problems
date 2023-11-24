const input = require('fs').readFileSync('/dev/stdin', 'utf8');
const lines = input.split('\n');

while (true) {
    const max = +lines.shift();
    if (max === 0) {
        break;
    }
    const discarded = [];

    const cards = new Array(max).fill(0).map((_, index) => index + 1);

    while (cards.length > 1) {
        discarded.push(cards.shift());
        cards.push(cards.shift());
    }

    console.log(`Discarded cards: ${discarded.join(', ')}`);
    console.log(`Remaining card: ${cards[0]}`);
}
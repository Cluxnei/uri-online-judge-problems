const input = require('fs').readFileSync('/dev/stdin', 'utf8');
const lines = input.split('\n');

while (true) {
    const n = +lines.shift();
    if (n === 0) {
        break;
    }
    const nums = lines.shift().split(' ').map(n => +n);
    nums.push(nums[0]);
    nums.unshift(nums[nums.length - 2]);
    const map = [];

    for (let i = 0; i < nums.length - 1; i++) {
        const diff = nums[i] - nums[i + 1];
        if (diff === 0) {
            continue;
        }
        map.push(diff < 0 ? 'd' : 'a');
    }

    let highs = 0;
    for (let i = 0; i < map.length - 1; i++) {
        if (map[i] !== map[i + 1]) {
            highs += 1;
        }
    }
    console.log(highs);
}
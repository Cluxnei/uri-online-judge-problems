const input = require('fs').readFileSync('/dev/stdin', 'utf8');
const lines = input.split('\n');

while (lines.length) {
    const [ax, ay, az, bx, by, bz] = lines.shift().split(' ').map(n => +n);
    let time = +lines.shift();
    const r = Math.hypot(ax, ay, az);
    const t = Math.PI * r * r * r; // find this value
    const x = ax * r * Math.cos(t) + bx * r * Math.sin(t);
    const y = ay * r * Math.cos(t) + by * r * Math.sin(t);
    const z = az * r * Math.cos(t) + bz * r * Math.sin(t);

    console.log(x, y, z);


}


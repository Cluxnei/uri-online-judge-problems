const input = require("fs").readFileSync("/dev/stdin", "utf8");
// const input = require("fs").readFileSync("./input.txt", "utf8");
const lines = input.split("\n");

class Vector3 {
    constructor(x = 0, y = 0, z = 0) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    sub(vector3) {
        return new Vector3(
            this.x - vector3.x,
            this.y - vector3.y,
            this.z - vector3.z,
        );
    }
    add(vector3) {
        return new Vector3(
            this.x + vector3.x,
            this.y + vector3.y,
            this.z + vector3.z,
        );
    }
    mag() {
        return Math.hypot(this.x, this.y, this.z);
    }
    scale(c) {
        return new Vector3(this.x * c, this.y * c, this.z * c);
    }
    norm() {
        const mag = this.mag();
        return new Vector3(this.x / mag, this.y / mag, this.z / mag);
    }
    static crossP(a, b) {
        const x = a.y * b.z - a.z * b.y;
        const y = a.z * b.x - a.x * b.z;
        const z = a.x * b.y - a.y * b.x;
        return new Vector3(x, y, z);
    }

    static internProduct(a, b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    static angleBetween(a, b) {
        return Math.acos(Vector3.internProduct(a, b) / (a.mag() * b.mag()));
    }
}

while (lines.length) {
    const line = lines.shift();
    if (!line || line.trim() === '') {
        break;
    }
    const [ax, ay, az, bx, by, bz] = line.split(" ").map(Number);
    const time = Number(lines.shift());
    const aVector = new Vector3(ax, ay, az);
    const bVector = new Vector3(bx, by, bz);
    const cVector = Vector3.crossP(aVector, bVector);
    const dVector = Vector3.crossP(aVector, cVector);
    const modD = dVector.norm();
    const modA = aVector.norm();
    const r = aVector.mag();
    const baseAngle = Vector3.angleBetween(aVector, bVector);

    const teta = -baseAngle * time;

    const x = r * Math.cos(teta) * modA.x + r * Math.sin(teta) * modD.x;
    const y = r * Math.cos(teta) * modA.y + r * Math.sin(teta) * modD.y;
    const z = r * Math.cos(teta) * modA.z + r * Math.sin(teta) * modD.z;

    const xRound = Number(x.toFixed(3)).toFixed(3);
    const yRound = Number(y.toFixed(3)).toFixed(3);
    const zRound = Number(z.toFixed(3)).toFixed(3);

    console.log(`${xRound} ${yRound} ${zRound}`);
}

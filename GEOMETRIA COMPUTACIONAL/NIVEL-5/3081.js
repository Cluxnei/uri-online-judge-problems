const input = require('fs').readFileSync('/dev/stdin', 'utf8');
const lines = input.split('\n');

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
            this.z - vector3.z
        );
    }
    add(vector3) {
        return new Vector3(
            this.x + vector3.x,
            this.y + vector3.y,
            this.z + vector3.z
        );
    }
    mag() {
        return Math.hypot(this.x, this.y, this.z);
    }
    scale(c) {
        return new Vector3(
            this.x * c,
            this.y * c,
            this.z * c
        );
    }
    norm() {
        const mag = this.mag();
        return new Vector3(
            this.x / mag,
            this.y / mag,
            this.z / mag
        )
    }
}

const out = (vector3) => {
    console.log(
        `${vector3.x.toFixed(3)} ${vector3.y.toFixed(3)} ${vector3.z.toFixed(3)}`
    );
};

const predictNextPositionBasedInFirstAndSecondPositions = (firstPositionVector3, secondPositionVector3) => {
    const diff = firstPositionVector3.sub(secondPositionVector3);
    const diffNorm = diff.norm();
    const diffMag = diff.mag();
    const projection = secondPositionVector3.add(diffNorm.scale(diffMag));
    return projection;
}


while (lines.length) {
    const [ax, ay, az, bx, by, bz] = lines.shift().split(' ').map(n => +n);
    const time = +lines.shift();

    let firstPosition = new Vector3(ax, ay, az);
    let secondPosition = new Vector3(bx, by, bz);


    if (time <= 1) {
        console.log(time === 0 ? out(firstPosition) : out(secondPosition));
        continue;
    }

    for (let i = 1; i < time; i++) {
        let aux = secondPosition;
        secondPosition = predictNextPositionBasedInFirstAndSecondPositions(firstPosition, secondPosition);
        firstPosition = aux;
    }

    out(secondPosition);
}


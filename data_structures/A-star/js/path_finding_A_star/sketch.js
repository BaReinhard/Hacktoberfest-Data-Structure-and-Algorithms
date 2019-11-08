var rows,colums,CanvasX,CanvasY;

CanvasX = CanvasY = 600;
rows = colums = 150;

var wallPrecentage = 0.3; //0 <= x <= 1


var grid = new Array(colums);
var openSet = [];
var closedSet = [];
var path = [];

var w,h,start,end;

removeFromArray = (arr,element) => {
    for (let i = arr.length-1; 0 <= i; i--) {
        if (arr[i] === element) {
            arr.splice(i, 1);
        }
    }
}

heuristic = (a,b) => abs(a.i - b.i) + abs(a.j - b.j); //dist(a.i,a.j,b.i,b.j);

class Spot {

    constructor(i, j) {

        this.f = 0;
        this.g = 0;
        this.h = 0;

        this.i = i;
        this.j = j;

        this.neighbors = [];
        this.previous  ;
        this.wall = false;

        if(random(1) < wallPrecentage)
            this.wall = true;


    }

    show(colums) {
        fill(colums);
        if(this.wall)
            fill(0);
        noStroke();
        rect(this.i*w,this.j*w,w-1,h-1);
    }

    addNeighbors(grid) {

        var i = this.i;
        var j = this.j;

        if(i < colums-1)
            this.neighbors.push(grid[i+1][j]);
        if(i > 0)
            this.neighbors.push(grid[i-1][j]);
        if(j < rows- 1 )
            this.neighbors.push(grid[i][j+1]);
        if(j > 0)
            this.neighbors.push(grid[i][j-1]);

        if(i > 0 && j > 0)
            this.neighbors.push(grid[i-1][j-1]);
        if(i < colums-1 && j > 0)
            this.neighbors.push(grid[i+1][j-1]);
        if(i > 0 && j < rows -1)
            this.neighbors.push(grid[i-1][j+1]);
        if(i < colums-1  && j < rows -1)
            this.neighbors.push(grid[i+1][j+1]);
    }
}

function setup() {
    let i;

    createCanvas(CanvasX,CanvasY);
    console.log("A*");

    w = width/colums;
    h = height/rows;

    for (i = 0; i < colums ; i++){
        grid[i] = new Array(rows);
    }

    for (i = 0; i < colums ; i++){
        for (var j= 0 ; j < rows ;j++){
            grid[i][j] = new Spot(i,j);
        }
    }

    for (i = 0; i < colums ; i++){
        for (var j= 0 ; j < rows ;j++){
            grid[i][j].addNeighbors(grid);
        }
    }

    start = grid[0][0];
    end = grid[colums-1][rows-1];
    start.wall = end.wall = false;

    openSet.push(start);
}

function draw() {

    let i;
    if (openSet.length > 0) {

        var winner = 0;
        for (i = 0; i < openSet.length; i++) {
            if (openSet[i].f < openSet[winner].f) {
                winner = i;
            }
        }

        var current = openSet[winner];

        if (current === end) {
            noLoop();
            console.log("done");
        }

        removeFromArray(openSet, current);
        closedSet.push(current);

        var neighbors = current.neighbors;

        for (i = 0; i < neighbors.length; i++) {
            var neighbor = neighbors[i];

            if (!closedSet.includes(neighbor) && !neighbor.wall) {
                var temp = current.g + 1;

                if (openSet.includes(neighbor)) {
                    if (temp < neighbor.g) {
                        neighbor.g = temp;
                    }
                } else {
                    neighbor.g = temp;
                    openSet.push(neighbor);
                }

                neighbor.h = heuristic(neighbor, end);
                neighbor.f = neighbor.g + neighbor.h;
                neighbor.previous = current;

            }
        }
    }else{
        console.log("no Solution");
        noLoop();
        return;
    }
    background(51);

    for (i = 0; i < colums; i++) {
        for (let j = 0; j < rows; j++) {
            grid[i][j].show(color(255));
        }
    }

    for (i = 0; i < closedSet.length; i++) {
        closedSet[i].show((color(255, 0, 0)));
    }

    for (i = 0; i < openSet.length; i++) {
        openSet[i].show((color(0, 255, 0)));
    }

        path = [];
        var temp = current;

        path.push(temp);
        while (temp.previous) {
            path.push(temp.previous);
            temp = temp.previous;
        }

    for (i = 0; i < path.length; i++){
        path[i].show((color(0,0,255)));
    }
}
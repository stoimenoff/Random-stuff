var canvas = document.getElementById("c");
var ctx = canvas.getContext("2d");
function randomInt (min, max) {
    return Math.round(Math.random() * (max - min) + min);
}
function Rock(x, y, speed, size){
		this.x = x;
		this.y = y;
		this.speed = speed;
		this.size = size;
		this.draw = function(ctx) {
			ctx.beginPath();
			ctx.moveTo(this.x, this.y);
			ctx.arc(this.x, this.y, this.size,  Math.PI/2, 2 * Math.PI +  Math.PI/2, false);
			ctx.stroke();
		};
		this.move = function() {
			this.y += this.speed;
		};
}
function Hero(x, y, speed, size){
		this.x = x;
		this.y = y;
		this.speed = speed;
		this.size = size;
		this.draw = function(ctx){
			ctx.beginPath();
			//legs
			ctx.moveTo(this.x, this.y);
			ctx.lineTo(this.x + 3*this.size, this.y - 4*this.size);
			ctx.lineTo(this.x + 6*this.size,this.y);
			//body
			ctx.moveTo(this.x + 3*this.size, this.y - 4*this.size);
			ctx.lineTo(this.x + 3*this.size,this.y - 9*this.size);
			//arms
			ctx.lineTo(this.x,this.y - 11*this.size);
			ctx.lineTo(this.x - this.size,this.y - 13*this.size);
			ctx.moveTo(this.x + 3*this.size,this.y - 9*this.size);
			ctx.lineTo(this.x + 6*this.size,this.y - 11*this.size);
			ctx.lineTo(this.x + 7*this.size,this.y - 13*this.size);
			//stick
			ctx.lineTo(this.x - this.size,this.y - 13*this.size);
			//head
			ctx.moveTo(this.x + 3*this.size, this.y - 10*this.size);
			ctx.arc(this.x + 3*this.size, this.y - 10*this.size, this.size,  Math.PI/2, 2 * Math.PI +  Math.PI/2, false);
			ctx.stroke();
		};
		this.moveLeft = function() {
			this.x -= speed;
		};
		this.moveRight = function() {
			this.x += speed;
		};
}
function createRandomRock(){
	var size = randomInt(5,15);
	var speed = randomInt(1,5);
	var x = randomInt(size,ctx.canvas.width - size);
	return new Rock(x,size,speed,size);
}
var rocks =[];
for(var i=0;i<5;i++){
	var rock = createRandomRock();
	rocks.push(rock);
}
var hero = new Hero(0,500,10,8);
window.addEventListener("keydown", function(e){
		switch (e.keyCode) {
			case 37:
				if(hero.x >= hero.speed)
				hero.moveLeft();
				break;
			case 39:
				if(hero.x <= ctx.canvas.width - 7*hero.size)
				hero.moveRight();
				break;
		}
});
var isAnimationOn = true;
function animationFrame(){
		ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
		hero.draw(ctx);
		var len = rocks.length;
		for(var i=0;i<len;i++){
			rocks[i].draw(ctx);
			rocks[i].move();
			if(rocks[i].y >= ctx.canvas.height - 13*hero.size - rocks[i].size && rocks[i].x >= hero.x - rocks[i].size && rocks[i].x <= hero.x + 6*hero.size + rocks[i].size)
			{
				isAnimationOn = false;
			}
			if(rocks[i].y >= ctx.canvas.height - rocks[i].size)
			{
				rocks.splice(i,1);
				rocks.push(createRandomRock());
				i--;
			}
		}
		if (isAnimationOn){
			requestAnimationFrame(animationFrame);
		}
}
requestAnimationFrame(animationFrame);
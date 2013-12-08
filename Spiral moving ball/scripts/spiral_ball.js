var canvas = document.getElementById("c");
var ctx = canvas.getContext("2d");
var centerx = ctx.canvas.width / 2;
var centery = ctx.canvas.height / 2;
var angle;
ctx.moveTo(centerx, centery);
//ctx.beginPath();
var x,y;
var i=0;

function animationFrame(){
	ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
	ctx.beginPath();
	angle = 0.1 * i;
	i+=1;
	x=centerx + (2+2*angle)*Math.cos(angle);
	y=centery + (2+2*angle)*Math.sin(angle);
	ctx.moveTo(x, y);
	ctx.arc(x, y, 10, 0, 2 * Math.PI, false);
	ctx.fillStyle = 'green';
	ctx.fill();
	if(x>ctx.canvas.width-10 || y>ctx.canvas.height-10){
		x = centerx;
		y = centery;
		i=0;
	}

	requestAnimationFrame(animationFrame);
}
requestAnimationFrame(animationFrame);

ctx.strokeStyle = "#000";
ctx.stroke();
(function () {
	function randomInt (min, max) {
    	return Math.round(Math.random() * (max - min) + min);
	}
	var canvas = document.getElementById("aircraft-canvas"),
		ctx = canvas.getContext("2d");

	function Laser(x, y, speed) {
		this.x = x;
		this.y = y;
		this.speed = speed;
		this.draw = function (ctx) {
			ctx.beginPath();
			ctx.moveTo(this.x, this.y);
			ctx.lineTo(this.x + 10, this.y);
			ctx.stroke();
		};

		this.move = function () {
			this.x += this.speed;
		};
	}

	function Fighter(x, y, speed) {
		var laserSpeed = 10;
		this.x = x;
		this.y = y;
		this.speed = speed;
		this.lasers = [];
		this.lives = 1;
		this.draw = function (ctx) {
			//body of the fighter
			ctx.beginPath();
			ctx.moveTo(this.x, this.y);
			ctx.lineTo(this.x, this.y - 30);
			ctx.lineTo(this.x + 20, (2 * this.y - 30) / 2);
			ctx.lineTo(this.x + 35, (2 * this.y - 30) / 2);

			//move after the wing
			ctx.moveTo(this.x + 75, (2 * this.y - 30) / 2);
			ctx.lineTo(this.x + 100, (2 * this.y - 30) / 2);
			ctx.lineTo(this.x + 120, this.y);
			ctx.lineTo(this.x, this.y);

			//top wing
			ctx.moveTo(this.x + 35, (2 * this.y - 30) / 2 + 5);
			ctx.lineTo(this.x + 35, (2 * this.y - 30) / 2 - 45);
			ctx.lineTo(this.x + 80, (2 * this.y - 30) / 2 + 5);

			//bottom cannon
			ctx.moveTo(this.x + 60, (2 * this.y - 30) / 2 - 10);
			ctx.lineTo(this.x + 80, (2 * this.y - 30) / 2 - 10);

			//middle cannon
			ctx.moveTo(this.x + 50, (2 * this.y - 30) / 2 - 20);
			ctx.lineTo(this.x + 70, (2 * this.y - 30) / 2 - 20);

			//top cannon
			ctx.moveTo(this.x + 40, (2 * this.y - 30) / 2 - 30);
			ctx.lineTo(this.x + 60, (2 * this.y - 30) / 2 - 30);
			ctx.strokeStyle = '#0000FF';
			ctx.stroke();

			//draw the lasers
			for (var i = 0; i < this.lasers.length; i += 1) {
				this.lasers[i].draw(ctx);
			}
		};

		this.moveUp = function () {
			this.y -= speed;
		};

		this.moveDown = function () {
			this.y += speed;
		};

		this.fire = function () {
			var laserStartPoints = [{
				x: this.x + 80,
				y: (2 * this.y - 30) / 2 - 10
			}, {
				x: this.x + 70,
				y: (2 * this.y - 30) / 2 - 20
			}, {
				x: this.x + 60,
				y: (2 * this.y - 30) / 2 - 30
			}, {
				x: this.x + 120,
				y: this.y
			}];
			//var laserPointIndex = (Math.random() * laserStartPoints.length) | 0;
			//var laserPoint = laserStartPoints[laserPointIndex];
			//var laser = new Laser(laserPoint.x, laserPoint.y, laserSpeed);
			//this.lasers.push(laser);
			for (var i = 0; i < laserStartPoints.length; i += 1) {
				var laser = new Laser(laserStartPoints[i].x, laserStartPoints[i].y, laserSpeed);
				this.lasers.push(laser);
			}
		};

		this.performMove = function (maxX) {
			var i;
			for (i = 0; i < this.lasers.length; i += 1) {
				if (this.lasers[i].x >= maxX) {
					this.lasers.splice(i, 1);
					i--;
				}
			}
			for (i = 0; i < this.lasers.length; i += 1) {
				this.lasers[i].move();
			}
		};

		this.amIDead = function(monsterX,monsterY,ctx){
			var imgData=ctx.getImageData(monsterX,monsterY,10,10);
			// invert colors
			for (var i=0;i<imgData.data.length;i+=4){
				if((imgData.data[i+2]) == 255){
					this.lives -= 1;
				}
			}
		};
	}
	function Monster(x,y,speed){
		this.x = x;
		this.y = y;
		this.speed = speed;
		this.draw = function(ctx){
			ctx.beginPath();
			ctx.moveTo(this.x,this.y);
			ctx.rect(this.x,this.y,10,10);
			ctx.strokeStyle = '#000000';
			ctx.stroke();
		}
		this.move = function(){
			this.x -= this.speed;
		}
	}
	function createRandomMonster(){
		var y = randomInt(0,ctx.canvas.height - 10);
		var x = randomInt(800,ctx.canvas.width - 10);
		var speed = randomInt(2,6);
		return new Monster(x,y,speed);
	}
	var fighter = new Fighter(20, 100, 15);
	var monsters = [];
	for(var i =0;i<20;i++){
		var monster = createRandomMonster();
		monsters.push(monster);
	}
	document.body.addEventListener("keydown", function (e) {
		if (!e) {
			e = window.event;
		}
		switch (e.keyCode) {
		case 38:
			fighter.moveUp();
			break;
		case 40:
			fighter.moveDown();
			break;
		case 32:
			fighter.fire();
			break;
		}
	});
	var isAnimationOn = true;
	var score = 0;
	var spanScore = document.getElementById('score');
	setInterval(function(){
		if(isAnimationOn){
			score +=1;
			spanScore.innerHTML = 'Score : ' + score;
		}
	},100);
	function animationFrame() {
		ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
		fighter.draw(ctx);
		fighter.performMove(ctx.canvas.width);
		for(var i =0;i<monsters.length;i++){
			if(monsters[i].x < 150){
				fighter.amIDead(monsters[i].x,monsters[i].y,ctx);
			}
			monsters[i].draw(ctx);
			monsters[i].move();
			if(monsters[i].x < 60)
			{
				monsters.splice(i,1);
				monsters.push(createRandomMonster());
				i--;
			}
			for(var k=0;k<fighter.lasers.length;k++){
				if(fighter.lasers[k] && monsters[i]){
					if(fighter.lasers[k].x + 10 >= monsters[i].x && fighter.lasers[k].y >= monsters[i].y && fighter.lasers[k].y <= monsters[i].y +10){
						monsters.splice(i,1);
						monsters.push(createRandomMonster());
						i--;
						fighter.lasers.splice(k,1);
						k--;
						score += 100;
						spanScore.innerHTML = 'Score : ' + score;
						//console.log(score);
					}
				}
			}
		}
		if(fighter.lives <= 0){
			alert('You score is ' + score + ' !!!');
			isAnimationOn = false;
		}
		if (isAnimationOn){
			requestAnimationFrame(animationFrame);
		}
	}

	requestAnimationFrame(animationFrame);
}());
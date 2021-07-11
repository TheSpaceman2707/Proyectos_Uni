var can1;
var ctx1;
var ang=0;
function inicio(){
	can1 = document.getElementById("canvas2");
	ctx1 = can1.getContext("2d");
	ctx1.translate(40, 40);
	marco();
	setInterval(seg, 800);
}

function marco(){
	ctx1.beginPath();
	ctx1.transform(1, 1, -.5, .21, 0, 0);
	ctx1.arc(0,0,30,0,2*Math.PI);
	ctx1.strokeStyle = "#6BF8FD";
	ctx1.lineWidth = 3;
	ctx1.stroke();
	ctx1.closePath();
}
function seg(){
	ctx1.clearRect(0, 0, 10, 10);
	ctx1.beginPath();
	ctx1.strokeStyle="red";
	ctx1.moveTo(0,0);
	ctx1.lineTo(0,10);
	ctx1.stroke();
	ctx1.closePath();
	ctx1.rotate(2*Math.PI/60);
	
}

addEventListener("load", inicio, false);
var can1;
var ctx1;

function inicio(){
	can1 = document.getElementById("canvas1");
	ctx1 = can1.getContext("2d");
	imagen();
}

function imagen(){
	var foto = new Image();
	foto.src="Img/kvothe3.png";
	foto.addEventListener("load", function(){
		ctx1.drawImage(foto, 0, 0, 400, 400);
		
		ctx1.transform(1, .5, -.5, 1, 5, 10);
		ctx1.drawImage(foto, 0, 0, 400, 400);
		
		ctx1.transform(3, .5, -.25, 1, -10, -10);
		ctx1.drawImage(foto, 0, 0, 200, 200);
		
		ctx1.putImageData(imagenData, 400, 400);
	});
}

addEventListener("load", inicio, false);
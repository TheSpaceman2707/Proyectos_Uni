var can1;
var ctx1;

function inicio(){
	can1 = document.getElementById("canvas1");
	ctx1 = can1.getContext("2d");
	imagen();
}

function imagen(){
	var foto = new Image();
	foto.src="Img/La-musica.jpg";
	foto.addEventListener("load", function(){
		ctx1.drawImage(foto, 0, 0, 400, 400);
		//ctx1.drawImage(foto, 130, 0, 400, 400, 0, 0, 400, 400);
		ctx1.translate(800, 0);
		ctx1.scale(-1, 1);
		ctx1.drawImage(foto, 0, 0, 400, 400);
		//ctx1.drawImage(foto, 130, 0, 400, 400, 0, 0, 400, 400);
		//Rojo
		var imagenData = ctx1.getImageData( 400, 0, 200, 200); 
		
		for(var i=0; i<=imagenData.data.length; i+=4 ){
			//var prom=(imagenData.data[i]+imagenData.data[i+1]+imagenData.data[i+2])/3;
			imagenData.data[i]= imagenData.data[i];
			imagenData.data[i+1]=0;
			imagenData.data[i+2]=0;
			imagenData.data[i+3]=255;	
		}
		
		ctx1.putImageData(imagenData, 400, 0);
		//cuadro amarillo
		var imagenData = ctx1.getImageData( 600, 0, 200, 200); 
		for(var i=0; i<=imagenData.data.length; i+=4 ){
			imagenData.data[i]=imagenData.data[i];
			imagenData.data[i+1]=imagenData.data[i+1];
			imagenData.data[i+2]=0;
			imagenData.data[i+3]=255;
		}
		
		ctx1.putImageData(imagenData, 600, 0);
		
		//cuadro azul
		var imagenData = ctx1.getImageData( 400, 200, 200, 200); 
		
		for(var i=0; i<=imagenData.data.length; i+=4 ){
			imagenData.data[i]= 0;
			imagenData.data[i+1]=0;
			imagenData.data[i+2]=imagenData.data[i+2];
			imagenData.data[i+3]=200;	
		}
		
		ctx1.putImageData(imagenData, 400, 200);
		
		//cuadro verde
		var imagenData = ctx1.getImageData( 600, 200, 200, 200); 
		
		for(var i=0; i<=imagenData.data.length; i+=4 ){
			imagenData.data[i]= 0;
			imagenData.data[i+1]=imagenData.data[i+1];
			imagenData.data[i+2]=0;
			imagenData.data[i+3]=255;	
		}
		
		ctx1.putImageData(imagenData, 600, 200);
		
	});
}

addEventListener("load", inicio, false);
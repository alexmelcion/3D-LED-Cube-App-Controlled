let backup="0-0"
let capas=1
let backcapa=0
let idbut
let backled

function clicked(idbut){    
    idbut = idbut.slice(1)
    for (let i=1; i<26;i+=1){
        document.getElementById(i).src="led-apagado.png"
    }
    if (backup==idbut+"-1"){
        document.getElementById(idbut).src="led-apagado.png"
        window.AppInventor.setWebViewString("0")
        idbut=idbut+"-0"
        backcapa=0
    }
    else{
        document.getElementById(idbut).src="led-encendido.png"
        window.AppInventor.setWebViewString(idbut+capas)
        idbut=idbut+"-1"
        backcapa=capas
    }
    backup=idbut
    backled=idbut
}

function up(){
    for (let i=1; i<26;i+=1){
        document.getElementById(i).src="led-apagado.png"
    }
    if (capas!=5){
        capas+=1
        document.getElementById("text").innerText= "Capa "+capas
    }
    void backupf()
}

function down(){
    for (let i=1; i<26;i+=1){
        document.getElementById(i).src="led-apagado.png"
    }
    if (capas!=1){
        capas-=1
        document.getElementById("text").innerText= "Capa "+capas
    }
    void backupf()
}

function backupf(){
    if (backcapa==capas){
        document.getElementById(backled.slice(0,-2)).src="led-encendido.png"
    }
}
var btn = document.getElementById('btn')
var cl=true
var cr=false

function leftClick() {
    if (cl==false){
        btn.style.left = '0'
        window.AppInventor.setWebViewString("1")
        cr=false
        cl=true
    }
}

function rightClick() {
    if (cr==false){
        btn.style.left = '120'
        window.AppInventor.setWebViewString("0")
        cr=true
        cl=false
    }
}
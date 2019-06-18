const names=["red","blue","green","orange","yellowgreen","darkblue","pinkblue","orangeDeam","orangeDull"];

function searchFunction()
{
var x=""
    const key=document.getElementById('name').value;
    const filter=names.filter((name) =>{return name.toLowerCase().startsWith(key.toLowerCase())});
    for(var i=0;i<filter.length;i++)
        x=x+"<li>"+filter[i]+"</li>";
    document.getElementById("mylist").innerHTML=x;
}
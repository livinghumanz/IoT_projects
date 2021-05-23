function show_and_select(x,y)
{
    var snav=['hworked','habout','hreach','hskill'];
    var divs=['about','skills','reachme','workedon','iot','web','part','sp','translate'];
    var l = snav.length;
    var l2=divs.length;
    for(i=0;i<l2;i++)
    {
        var d=document.getElementById(divs[i]);
        if(i<l){
        var e=document.getElementById(snav[i]);
        if(x.id == snav[i])
        {
            x.style.textShadow="1px 2px 30px #f7b993 ";
            x.style.textDecoration="underline #29c5ab";
            x.style.textDecoration="underline 3px #29c5ab";
            
        }

        else
        {
            e.style.textShadow="none";
            e.style.textDecoration="none";
        }}
        if(y==divs[i])
        {
            d.style.display="block";
            if(y=='skills')
              move();
            
            
        }
        else{ 
            d.style.display="none";}

    }
}
//--------------------loading skill set-------------------------------
function move()
{
  var dictele={'c':75,'python':70,'embeded':55,'js':50,'php':30,'cpp':60,'cv':40,'css':40,'java':50}
  for(var k in dictele)
    {
      ele(k,dictele);
      }
 }
function ele(k,dictele)
{
  var elem = document.getElementById(k);   
      var width = 1;
      var id = setInterval(frame, 30);
      function frame() {
        if (width >= dictele[k]) {
          clearInterval(id);
        } else {
          width++; 
          elem.style.width = width + '%'; 
        }
      }
}
function hseek(h_div,s_div)
{
  document.getElementById(h_div).style.display="none";
  document.getElementById(s_div).style.display="block";
  
}
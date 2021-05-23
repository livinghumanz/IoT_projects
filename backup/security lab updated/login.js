 // Get the modal
 var modal = document.getElementById('id01');
 var modal2= document.getElementById('id02');
 var sin = document.getElementById('sin');
            
// When the user clicks anywhere outside of the modal, close it
 window.onclick = function(event) 
{
    if (event.target == modal) 
    {
        modal.style.display = "none";
    }
}
window.onclick = function(event) 
{
    if (event.target == modal2) 
    {
        modal.style.display = "none";
    }
}
function hide()
{
   if(sin.onclick)
   {
       modal.style.display= "none";
       modal2.style.display= "block";
   }
}

/**************************************Validation of Contact *************************** */


  function popup1()
  {
    document.getElementById('id01').style.display='none';
    document.getElementById('id02').style.display='block';
  }
  function popup2()
  {
    document.getElementById('id01').style.display='block';
    document.getElementById('id02').style.display='none';
  }
 // <!---------------------------------------driver script-------------------------------->
 //   <script> 
    $(document).ready(function() {
            $('#textarea').val("");
           });
  
      function whenkeyup(url){
        var valuegot,length=0,array=[],str='<select id="updatedir" onclick="func();" class="noborder" style="font-size:16pt;font-style: italic;width:100px;height:40px;" >';
        fetch(url)
        .then(res => res.json())
        .then((out) => {
            //console.log('Output: ', out.itrans);
            var i;
            length=(out.twords[0].options).length;
            for(i=0;i<length;i++){
              str=str+'<option value="';
              str=str+out.twords[0].options[i]+'">'+out.twords[0].options[i]+'</option>';
            //array.push(out.twords[0].options[i]);
            //alert(array);
            }
            /*rray=[];*/
            str+='</select>';
            //alert(str);
            fundo(str);
            str='';
    }).catch(err => console.error(err));
      }
   //   </script> 
  //<!-------------------------------------------------End driver script-------------------------------------->
 
  //<!----------------------------control script code------------------------------------------------------->                             
  //<script>
  var count=0;
          function fun()
          {
              var lang=document.getElementById("selection").value;
              var txtval=document.getElementById("textarea").value;
              var atxtval=txtval.split(' ');
              var length=atxtval.length;
              var txtvalue=atxtval[length-1];
              //alert(txtvalue);
              var url="http://146.148.85.67/processWordJSON?inString="+txtvalue+"&lang="+lang;
              var str=whenkeyup(url);
              //return str;
              //alert(url);
          }

        function fundo(str){
        $(document).ready(function(){
       
               $('#demo').html(str);
             // $('demo').show(2000);
        });
        }
        function func(){
        count=parseInt(count)+1;
        if(parseInt(count)%2==0)
        {
        var nchar=document.getElementById("updatedir").value;
        var tarea=document.getElementById("textarea");
        var atxtaval=tarea.value.split(' ');
        atxtaval[atxtaval.length-1]=nchar;
        tarea.value=atxtaval.join(' ')+' ';
       // document.getElementById("tags").value='';
        $(document).ready(function(){
       
       $('#demo').html('');
       tarea.focus();
     // $('demo').show(2000);
          });
          
        }

        }
        //document.getElementById("demo").style.display="none";
 // </script>
//<!---------------------------------------control script  End code-------------------------------->
//<!---------------------------------------control script  for cookie session -------------------------------->
//<script>
var expDays = 30;	// set this value to however many days you want your cookies to last

function setCookie(name, val)
{
var exp = new Date()
var cookieTimeToLive = exp.getTime() + (expDays * 24 * 60 * 60 * 1000)
exp.setTime(cookieTimeToLive)
document.cookie = name + "=" + escape(val) + "; expires=" + exp.toGMTString()
}

function getCookie(name)
{
var cookieNameLen = name.length
var cLen = document.cookie.length
var i = 0
var cEnd
var myStringToReturn
var myStringToReturnLen
while (i < cLen) 
{
var j = i + cookieNameLen
if (document.cookie.substring(i,j) == name)
{
cEnd = document.cookie.indexOf(";",j)
if (cEnd == -1)
{
 cEnd = document.cookie.length
}
myStringToReturn = unescape(document.cookie.substring(j,cEnd))
myStringToReturnLen = myStringToReturn.length
myStringToReturn = myStringToReturn.substring(1,myStringToReturnLen+1)
return myStringToReturn
}
i++
}
return ""
}

//</script>
//<!---------------------------------------control script  for cookie session end-------------------------------->
<!DOCTYPE html>
<html>
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<style>
    html { 
        scroll-behavior: smooth; 
        scrollbar-width: auto;
        }
    div {
            resize: none;
            overflow: auto;
            scrollbar-width: none;
        }
   body {
  background: #fafafa;
  color: #333333;
  margin-top: 5rem;
}

h1, h2, h3, h4, h5, h6 {
  color: #444444;
}

.bg-steel {
  background-color: #5f788a;
}

.site-header .navbar-nav .nav-link {
  color: #cbd5db;
}

.site-header .navbar-nav .nav-link:hover {
  color: #ffffff;
}

.site-header .navbar-nav .nav-link.active {
  font-weight: 500;
}
.images{
max-width:100%;
max-height:100%;
}

.content-section {
  background: pink;
  padding: 15px 15px;
  border: 1px solid #dddddd;
  border-radius: 3px;
  /*margin-bottom: 20px;*/
  position:fixed;
  /*top:70px;*/
  max-width:100%;
  max-height:100%;
}

.article-title {
  color: #444444;
}

a.article-title:hover {
  color: #428bca;
  text-decoration: none;
}

.article-content {
  white-space: pre-line;
}

.article-img {
  height: 65px;
  width: 65px;
  margin-right: 16px;
}

.article-metadata {
  padding-bottom: 1px;
  margin-bottom: 4px;
  border-bottom: 1px solid #e3e3e3
}

.article-metadata a:hover {
  color: #333;
  text-decoration: none;
}

.article-svg {
  width: 25px;
  height: 25px;
  vertical-align: middle;
}

</style>

        <title>Deflate</title>

</head>
<body onload="loadAll()" >
    <header class="site-header">
      <nav class="navbar navbar-expand-md navbar-dark bg-steel fixed-top">
        <div class="container" >
          <a class="navbar-brand mr-4" href="/Deflate">Deflate</a>
          
          <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarToggle" aria-controls="navbarToggle" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
          </button>
          
          <div class="collapse navbar-collapse" id="navbarToggle" >
            <div class="navbar-nav mr-auto" >
              <a class="nav-item nav-link" href="/Deflate">Home</a>
              
              <a class="nav-item nav-link dropdown-toggle" id="dropdown" href="#" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false" style="position:relative;" onmouseover="click()">Page Navigation</a>
              <div class = "dropdown-menu" aria-labelledby="dropdown" style="right:0%;">
                  <a class="dropdown-item" href="#history" >History</a>
                  <div class="dropdown-divider"></div>
                  <a class="dropdown-item" href="#LZ77" >LZ77</a>
                  <div class="dropdown-divider"></div>
                  <a class="dropdown-item" href="#Huffman">Huffman</a>
                  <div class="dropdown-divider"></div>
                  <a class="dropdown-item" href="#Deflate">Deflate</a>
                  <div class="dropdown-divider"></div>
                  <a class="dropdown-item" href="#download">Codes</a>
                  <div class="dropdown-divider"></div>
                  <a class="dropdown-item" href="#Reference">References</a>
              </div>
              
              <a class="nav-item nav-link" href="/About">About</a>
              
            </div>
            <!-- Navbar Right Side -->
            <div class="navbar-nav">

<!--Empty for now-->

            </div>
          </div>
        </div>
      </nav>
    </header>
    <div>
    <main role="main" class="container" >
      <div class="row">
        <div class="col-md-9">

          <div id="history">
              <h3><u><p><strong>History of Deflate:</strong></p></u></h3>
              <div id="DeflateExplain"></div>
          </div>
          
          <br><br><br>
          <div id="LZ77">
              <h3><u><p><strong>LZ77:</strong></p></u></h3>
              <div id="LZExplain" ></div>
              <br>
              
              <p><strong>Pseudo LZ77:</strong></p>
              
              <div name="text" style="font-style:italic;height:100%;width:100%;padding:2%;font: sans-serif;color:black; background-color: rgba(0,255,255,0.2);"readonly><em id="LZPseudo">
                <br><br>
              </em></div>
              
              <br><br>
              <center><div style="border: 1px solid black;">
                  <figure class = "figure">
                  <a target="_blank">
                  <img src="/LZ77.gif" class="images figure-img img-fluid" id="LZ-gif">
                  <figcaption class = "figure-caption">LZ77 animation walkthrough</figcaption>
                  </a>
                  </figure>
                  </div></center>
              <br>
              <button class="btn btn-outline-primary btn-block" value="refreshLZ" onclick="document.getElementById('LZ-gif').src='/LZ77.gif'" /><i class="fa fa-refresh"></i> Restart Animation</button>
          </div> 
          <br><br><br><br>
          <!--End LZ77-->
          
          
          <div id="Huffman">
              <h3><u><p><strong>Huffman:</strong></p></u></h3>
              <div id="HuffExplain" ></div>
              <br>
              
              <p><strong>Pseudo Huffman:</strong></p>
              
              <div name="text" style="font-style:italic;height:100%;width:100%;padding:2%;font:sans-serif;color:black; background-color: rgba(0,255,255,0.2);"readonly><em id="HuffPseudo">
                <br><br>
              </em></div>
              
              <br><br>
              <center><div style="border: 1px solid black;">
                  <figure class = "figure">
                  <a target="_blank">
                  <img src="/Huffman.gif" class="images figure-img img-fluid" id="Huff-gif">
                  <figcaption class = "figure-caption">Huffman Coding animation walkthrough</figcaption>
                  </a>
                  </figure>
                  </div></center>
              <br>
              <button class="btn btn-outline-primary btn-block" value="refreshHuff" onclick="document.getElementById('Huff-gif').src='/Huffman.gif'" /><i class="fa fa-refresh"></i> Restart Animation</button>
              
          </div>
          <br><br><br><br>
          <!--End Huffman-->
          
          
          <div id="Deflate">
              <h3><u><p><strong>Deflate:</strong></p></u></h3>
              <div id="DeflateExplain2" ></div>
              <br>
              
              <p><strong>Pseudo Deflate:</strong></p>
              
              <div name="text" style="font-style:italic;height:100%;width:100%;padding:2%;font:sans-serif;color:black; background-color: rgba(0,255,255,0.2);"readonly><em id="DeflatePseudo">
                <br><br>
              </em></div>
              
              <br><br>
              <center><div style="border: 1px solid black;">
                  <figure class = "figure">
                  <a target="_blank">
                  <img src="/Deflate.gif" class="images figure-img img-fluid" id="Deflate-gif">
                  <figcaption class = "figure-caption">Deflate animation walkthrough with changes to LZ77 & Huffman Coding</figcaption>
                  </a>
                  </figure>
                  </div></center>
              <br>
              <button class="btn btn-outline-primary btn-block" value="refreshDeflate" onclick="document.getElementById('Deflate-gif').src='/Deflate.gif'" /><i class="fa fa-refresh"></i> Restart Animation</button>
              
              
          </div> 
          <br><br><br><br>
           <!--End Deflate-->
          
           
          <div id="download">
              <h3><u><p><strong>Codes:</strong></p></u></h3>
              <a href="/Deflate/Placeholder.exe" download="Huffmancode.cpp"><i class="fa fa-download"></i> Download LZ77 Code Here </a><br>
              <a href="/Deflate/Placeholder.exe" download="Huffmancode.cpp"><i class="fa fa-download"></i> Download Huffman Code Here </a><br>
              <a href="/Deflate/Placeholder.exe" download="Huffmancode.cpp"><i class="fa fa-download"></i> Download Deflate Code Here </a><br>
              <a href="/Deflate/Placeholder.exe" download="Huffmancode.cpp"><i class="fa fa-download"></i> Download Inflate Code Here </a><br>
          </div>
          <br><br><br><br>
          <!--End Download-->
          
          
          <div id = "Reference">
              <h3><u><p><strong>References:</strong></p></u></h3>
              <center>
                  <em>References are in MLA version 8:</em><br>
                  Madler. “Madler/Zlib.” GitHub, <a href="https://github.com/madler/zlib/blob/master/contrib/puff/puff.c">https://github.com/madler/zlib/blob/master/contrib/puff/puff.c</a>.<br>
                  “Zlib.” Zlib, <a href="https://www.zlib.net">https://www.zlib.net/</a>.  <br><br>
                 
                 - Deflate -<br>
                 “DEFLATE Compressed Data Format Specification Version 1.3.” IETF Tools, <a href="https://tools.ietf.org/html/rfc1951">https://tools.ietf.org/html/rfc1951.</a><br>
                  “History of Lossless Data Compression Algorithms.” History of Lossless Data Compression Algorithms - Engineering and Technology History Wiki, <a href="https://ethw.org/History_of_Lossless_Data_Compression_Algorithms">https://ethw.org/History_of_Lossless_Data_Compression_Algorithms.</a><br>
                  “US5051745A - String Searcher, and Compressor Using Same.” Google Patents, Google, <a href="https://patents.google.com/patent/US5051745">https://patents.google.com/patent/US5051745.</a><br><br>
                  
                 - LZ77 -<br>
                  Elegant Compression in Text (The LZ 77 Method) – Computerphile, YouTube, <a href="https://www.youtube.com/watch?v=goOa3DGezUA">https://www.youtube.com/watch?v=goOa3DGezUA.</a><br>
                  “LZ-77.” Data Compression - LZ-77, <a href="http://www.stringology.org/DataCompression/lz77/index_en.html">http://www.stringology.org/DataCompression/lz77/index_en.html.</a><br>
                   The LZ77 Compression Family (Ep 2, Compressor Head) by Google Developers, YouTube, <a href="https://www.youtube.com/watch?v=Jqc418tQDkg">https://www.youtube.com/watch?v=Jqc418tQDkg.</a><br><br>
                   
                  - Huffman -<br>
                  “Discovery of Huffman Codes.” Discovery of Huffman Codes | Mathematical Association of America, <a href="https://www.maa.org/press/periodicals/convergence/discovery-of-huffman-codes">https://www.maa.org/press/periodicals/convergence/discovery-of-huffman-codes.</a><br>
                  Huffman Coding Algorithm, <a href="https://www.tutorialspoint.com/Huffman-Coding-Algorithm">https://www.tutorialspoint.com/Huffman-Coding-Algorithm.</a><br>

                 

                  
                  
              </center>
          </div>
          <br><br><br><br>
         <!--End References-->
          
        </div>
        <div class="col-md-1"></div>
        <div class="col-md-2">

            <div><a style="overflow:auto;height: 85%; position:fixed;resize:none;max-width:70%;scrollbar-width: none;"href="https://www.ucf.edu/" target="_blank"><img src="/ucf.jpg" style="height: inherit;" class="img-fluid"></a></div>
        <!--  <div class="content-section">-->
        <!--    <h3>Our Sidebar</h3>-->
        <!--    <p class='text-muted'>Deflate scroll section-->
        <!--      <ul class="list-group">-->
        <!--        <a href="#history"><button class="btn btn-outline-primary btn-block" value="section1" style="max-width:100%;max-height:100%;">History</button></a>-->
        <!--        <a href="#LZ77"><button class="btn btn-outline-primary btn-block" value="section2" style="max-width:100%;max-height:100%;">LZ77</button></a>-->
        <!--        <a href="#Huffman"><button class="btn btn-outline-primary btn-block" value="section3" style="max-width:100%;max-height:100%;">Huffman</button></a>-->
        <!--        <a href="#Deflate"><button class="btn btn-outline-primary btn-block" value="section4" style="max-width:100%;max-height:100%;">Deflate</button></a>-->
        <!--        <a href="/Deflate/Placeholder.exe" download="LZ77code.exe"><button class="btn btn-warning btn-block" style="max-width:100%;max-height:100%;"><i class="fa fa-download"></i>Download LZ77 Code Here</button></a>-->
        <!--        <a href="/Deflate/Placeholder.exe" download="Huffmancode.exe"><button class="btn btn-warning btn-block" style="max-width:100%;max-height:100%;"><i class="fa fa-download"></i>Download Huffman Code Here</button></a>-->
        <!--        <a href="/Deflate/Placeholder.exe" download="Deflatecode.zip"><button class="btn btn-warning btn-block" style="max-width:100%;max-height:100%;"><i class="fa fa-download"></i>Download Deflate Code Here</button></a>-->
        <!--      </ul>-->
        <!--    </p>-->
        <!--  </div>-->
        </div>
      </div>
    </main>
    </div>

    <script>
        function loadAll()
        {
            // load first part
            var txtFile = new XMLHttpRequest();
            var allText = "file not found";
            txtFile.onreadystatechange = function () 
            {
                if (txtFile.readyState === XMLHttpRequest.DONE && txtFile.status == 200) 
                {
                    allText = txtFile.responseText;
                    allText = allText.split("\n").join("<br>");
                }

            document.getElementById('DeflateExplain').innerHTML = allText;
            }
            txtFile.open("GET", '/Deflate/DeflateExplain.doc', true);
            txtFile.send(null);
        
            //load LZ77
            var txtFile2 = new XMLHttpRequest();
            var allText2 = "file not found";
            txtFile2.onreadystatechange = function () 
            {
                if (txtFile2.readyState === XMLHttpRequest.DONE && txtFile2.status == 200) 
                {
                    allText2 = txtFile2.responseText;
                    allText2 = allText2.split("\n").join("<br>");
                }

            document.getElementById('LZExplain').innerHTML = allText2;
            }
            txtFile2.open("GET", '/Deflate/LZExplain.doc', true);
            txtFile2.send(null);
            
            
            //load Huffman
            var txtFile3 = new XMLHttpRequest();
            var allText3 = "file not found";
            txtFile3.onreadystatechange = function () 
            {
                if (txtFile3.readyState === XMLHttpRequest.DONE && txtFile3.status == 200) 
                {
                    allText3 = txtFile3.responseText;
                    allText3 = allText3.split("\n").join("<br>");
                }

            document.getElementById('HuffExplain').innerHTML = allText3;
            }
            txtFile3.open("GET", '/Deflate/HuffExplain.doc', true);
            txtFile3.send(null);
            
            
            
            //load Deflate Difference
            var txtFile4 = new XMLHttpRequest();
            var allText4 = "file not found";
            txtFile4.onreadystatechange = function () 
            {
                if (txtFile4.readyState === XMLHttpRequest.DONE && txtFile4.status == 200) 
                {
                    allText4 = txtFile4.responseText;
                    allText4 = allText4.split("\n").join("<br>");
                }

            document.getElementById('DeflateExplain2').innerHTML = allText4;
            }
            txtFile4.open("GET", '/Deflate/DeflateExplain2.doc', true);
            txtFile4.send(null);
            
            
            
            //Load LZ Pseudo
            var txtFile5 = new XMLHttpRequest();
            var allText5 = "file not found";
            txtFile5.onreadystatechange = function () 
            {
                if (txtFile5.readyState === XMLHttpRequest.DONE && txtFile5.status == 200) 
                {
                    allText5 = txtFile5.responseText;
                    allText5 = allText5.split("\n").join("<br>");
                }

            document.getElementById('LZPseudo').innerHTML = allText5;
            }
            txtFile5.open("GET", '/Deflate/LZPseudo.txt', true);
            txtFile5.send(null);
            
            
            //Load Huff Pseudo
            var txtFile6 = new XMLHttpRequest();
            var allText6 = "file not found";
            txtFile6.onreadystatechange = function () 
            {
                if (txtFile6.readyState === XMLHttpRequest.DONE && txtFile6.status == 200) 
                {
                    allText6 = txtFile6.responseText;
                    allText6 = allText6.split("\n").join("<br>");
                }

            document.getElementById('HuffPseudo').innerHTML = allText6;
            }
            txtFile6.open("GET", '/Deflate/HuffPseudo.txt', true);
            txtFile6.send(null);
            
            
            //Load Deflate Pseudo
            var txtFile7 = new XMLHttpRequest();
            var allText7 = "file not found";
            txtFile7.onreadystatechange = function () 
            {
                if (txtFile7.readyState === XMLHttpRequest.DONE && txtFile7.status == 200) 
                {
                    allText7 = txtFile7.responseText;
                    allText7 = allText7.split("\n").join("<br>");
                }

            document.getElementById('DeflatePseudo').innerHTML = allText7;
            }
            txtFile7.open("GET", '/Deflate/DeflatePseudo.txt', true);
            txtFile7.send(null);
        }
    </script>

    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
</body>
</html>
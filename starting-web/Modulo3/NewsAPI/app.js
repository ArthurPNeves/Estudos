const API_KEY = 'acc744d45403465b8c4f7beabc1daff7';
function exibeNoticias () {
    let divTela = document.getElementById('tela');
    let texto = '';

    // Montar texto HTML das noticias
    let dados = JSON.parse (this.responseText);
    for (i=0; i< dados.articles.length; i++) {
        let noticia = dados.articles[i];
        let data = new Date (noticia.publishedAt);

        texto = texto + `
            <div class="box-noticia">
                <img src="${noticia.urlToImage}" alt="">
                <span class="titulo">${noticia.title}</span><br>
                <span class="creditos">${data.toLocaleDateString ()} - 
                    ${noticia.source.name} - 
                    ${noticia.author}</span><br>
                <span class="text">
                ${noticia.content} <a href="${noticia.url}">Leia mais ...</a>
                </span>
            </div>            
        `;
    };

    // Preencher a DIV com o texto HTML
    divTela.innerHTML = texto;
}

function executaPesquisa () {
    let query = document.getElementById('txtPesquisa').value;

    let xhr = new XMLHttpRequest ();
    xhr.onload = exibeNoticias;
    xhr.open ('GET', `https://newsapi.org/v2/everything?q=${query}&apiKey=${API_KEY}`);
    xhr.send ();
}

document.getElementById ('btnPesquisa').addEventListener ('click', executaPesquisa);
function exibeNoticias (){
    let divTela = document.getElementById('tela');
    let texto = '';

    let dados = JSON.parse (this.responseText);
    for (i = 0; i < dados.articles.length; i++) {
        let noticia = dados.articles[i];
       let data = new Date (noticia.publishedAt);
        texto = texto + 
        `
        <div class="box-noticia">
    <img src="${noticia.urlToImage}" alt="">
    <span class="titulo">  ${noticia.title}</span>
    <span class="creditos"> ${data.toLocaleDateString ()} - ${noticia.source.name} - ${noticia.author} <br></span>
    <span class="text"> 
    ${noticia.content} <a href="${noticia.url}">Leia mais ...</a>
    </span>
</div>
`;
 };
    divTela.innerHTML = texto;
}
function executaPesquisa(){
let query = document.getElementById('txtPesquisa').value;
let xhr = new XMLHttpRequest ();
xhr.onload = exibeNoticias; 
xhr.open ('GET', `https//newsapi.org/v2/everything?q=${query}bitcoin&apiKey=${API_KEY}`);
xhr.send();
}

document.getElementById ('btnPesquisa').addEventListener ('click', executaPesquisa);
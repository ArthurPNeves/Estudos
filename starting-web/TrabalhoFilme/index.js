const API_KEY  = '97be3f94220810b7fcefe5fe6c36bad1';
const BASE_API_URL = 'https://api.themoviedb.org/3/';
const BASE_IMG_URL = 'http://image.tmdb.org/t/p/w342/';

let listaGeneros = [];
let listaEmCartaz = [];

document.getElementById("pesquisa-form").addEventListener("submit", function(e) {
	window.location.href = `/pesquisa.html?query=${document.getElementById("input-search").value}`;
	e.preventDefault();
});

buscaInformacoesIniciais();
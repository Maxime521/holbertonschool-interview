#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];

if (!movieId) {
  process.exit(0);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(filmUrl, (err, response, body) => {
  if (err) {
    return;
  }

  if (response.statusCode !== 200) {
    return;
  }

  let filmData;
  try {
    filmData = JSON.parse(body);
  } catch (e) {
    return;
  }

  const characters = filmData.characters || [];

  const printCharacters = (index) => {
    if (index >= characters.length) {
      return;
    }

    request(characters[index], (charErr, charResponse, charBody) => {
      if (!charErr && charResponse.statusCode === 200) {
        try {
          const characterData = JSON.parse(charBody);
          console.log(characterData.name);
        } catch (e) {
        }
      }
      printCharacters(index + 1);
    });
  };

  printCharacters(0);
});

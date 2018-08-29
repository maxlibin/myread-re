// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");

function imageLinksJson(json) {
  return /* record */[
          /* smallThumbnail */Json_decode.field("smallThumbnail", Json_decode.string, json),
          /* thumbnail */Json_decode.field("smallThumbnail", Json_decode.string, json)
        ];
}

function booktypesSearch(json) {
  return /* record */[
          /* allowAnonLogging */Json_decode.field("allowAnonLogging", Json_decode.bool, json),
          /* authors */Json_decode.optional((function (param) {
                  return Json_decode.field("authors", (function (param) {
                                return Json_decode.list(Json_decode.string, param);
                              }), param);
                }), json),
          /* canonicalVolumeLink */Json_decode.field("canonicalVolumeLink", Json_decode.string, json),
          /* categories */Json_decode.optional((function (param) {
                  return Json_decode.field("categories", (function (param) {
                                return Json_decode.list(Json_decode.string, param);
                              }), param);
                }), json),
          /* contentVersion */Json_decode.field("contentVersion", Json_decode.string, json),
          /* description */Json_decode.optional((function (param) {
                  return Json_decode.field("description", Json_decode.string, param);
                }), json),
          /* id */Json_decode.field("id", Json_decode.string, json),
          /* imageLinks */Json_decode.field("imageLinks", imageLinksJson, json),
          /* infoLink */Json_decode.field("infoLink", Json_decode.string, json),
          /* language */Json_decode.field("language", Json_decode.string, json),
          /* maturityRating */Json_decode.field("maturityRating", Json_decode.string, json),
          /* pageCount */Json_decode.optional((function (param) {
                  return Json_decode.field("pageCount", Json_decode.$$int, param);
                }), json),
          /* previewLink */Json_decode.field("previewLink", Json_decode.string, json),
          /* printType */Json_decode.field("printType", Json_decode.string, json),
          /* publishedDate */Json_decode.field("publishedDate", Json_decode.string, json),
          /* shelf */Json_decode.optional((function (param) {
                  return Json_decode.field("shelf", Json_decode.string, param);
                }), json),
          /* title */Json_decode.field("title", Json_decode.string, json)
        ];
}

var bookshelfs = /* :: */[
  /* record */[
    /* title */"Currently Reading",
    /* key */"currentlyReading"
  ],
  /* :: */[
    /* record */[
      /* title */"Want To Read",
      /* key */"wantToRead"
    ],
    /* :: */[
      /* record */[
        /* title */"Read",
        /* key */"read"
      ],
      /* [] */0
    ]
  ]
];

var api = "https://reactnd-books-api.udacity.com";

exports.bookshelfs = bookshelfs;
exports.imageLinksJson = imageLinksJson;
exports.booktypesSearch = booktypesSearch;
exports.api = api;
/* No side effect */
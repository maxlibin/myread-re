// Generated by BUCKLESCRIPT VERSION 4.0.0, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var React = require("react");
var Belt_List = require("bs-platform/lib/js/belt_List.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var RR$ReactTemplate = require("../RR.bs.js");

var component = ReasonReact.statelessComponent("Bookshelf");

function make($staropt$star, $staropt$star$1, books, _) {
  var title = $staropt$star !== undefined ? $staropt$star : "";
  var shelf = $staropt$star$1 !== undefined ? $staropt$star$1 : "";
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              var books$1 = List.filter((function (book) {
                        return book[/* shelf */14] === shelf;
                      }))(Belt_List.fromArray(books));
              console.log(books$1);
              return React.createElement("div", {
                          className: "bookshelf"
                        }, React.createElement("h2", {
                              className: "bookshelf-title"
                            }, React.createElement("span", undefined, RR$ReactTemplate.string(title))), React.createElement("div", {
                              className: "bookshelf-books"
                            }, React.createElement("ol", {
                                  className: "books-grid"
                                }, React.createElement("div", {
                                      className: "book"
                                    }, React.createElement("div", {
                                          className: "book-top"
                                        }, React.createElement("div", {
                                              className: "book-shelf-changer"
                                            }))))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */

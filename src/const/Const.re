type shelfs = {
 title: string,
 key: string
};

type bookShelfs = list(shelfs);

let bookshelfs = [
  { title: "Currently Reading", key: "currentlyReading" },
  { title: "Want To Read", key: "wantToRead" },
  { title: "Read", key: "read" },
];

[@bs.deriving abstract]
type imageLinks = {
  smallThumbnail: string,
  thumbnail: int,
};

[@bs.deriving abstract]
type industryIdentifiers = {
  _type: string,
  identifier: string
};

[@bs.deriving abstract]
type panelizationSummary = {
  containsEpubBubbles: bool,
  containsImageBubbles: bool
};

[@bs.deriving abstract]
type ratingsCount = {
  image: bool,
  text: bool
};

[@bs.deriving abstract]
type books = {
  [@bs.optional] allowAnonLogging: bool,
  [@bs.optional] authors: list(string),
  [@bs.optional] averageRating: int,
  [@bs.optional] canonicalVolumeLink: string,
  [@bs.optional] categories: list(string),
  [@bs.optional] contentVersion: string,
  [@bs.optional] description: string,
  [@bs.optional] id: string,
  [@bs.optional] imageLinks: imageLinks,
  [@bs.optional] industryIdentifiers: list(industryIdentifiers),
  [@bs.optional] infoLink: string,
  [@bs.optional] language: string,
  [@bs.optional] maturityRating: string,
  [@bs.optional] pageCount: int,
  [@bs.optional] panelizationSummary: panelizationSummary,
  [@bs.optional] previewLink: string,
  [@bs.optional] printType: string,
  [@bs.optional] publishedDate: string,
  [@bs.optional] publisher: string,
  [@bs.optional] ratingsCount: ratingsCount,
  [@bs.optional] readingModes: string,
  [@bs.optional] shelf: string,
  [@bs.optional] subtitle: string,
  [@bs.optional] title: string
};

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

type imageLinks = {
  smallThumbnail: string,
  thumbnail: string,
};

type industryIdentifiers = {
  _type: string,
  identifier: string
};

type panelizationSummary = {
  containsEpubBubbles: bool,
  containsImageBubbles: bool
};

type ratingsCount = {
  image: bool,
  text: bool
};


let imageLinksJson = json =>
  Json.Decode.{
    smallThumbnail: json |> field("smallThumbnail", string),
    /* smallThumbnail: json |> optional(field("smallThumbnail", string)), */
    /* thumbnail: json |> optional(field("smallThumbnail", string)), */
    thumbnail: json |> field("smallThumbnail", string),
  };


type booksTypeSearch = {
  allowAnonLogging: bool,
  authors: option(list(string)),
  /* averageRating: int, */
  canonicalVolumeLink: string,
  categories: option(list(string)),
  contentVersion: string,
  description: option(string),
  id: string,
  imageLinks: imageLinks,
  /* industryIdentifiers: list(industryIdentifiers), */
  infoLink: string,
  language: string,
  maturityRating: string,
  pageCount: option(int),
  /* panelizationSummary: panelizationSummary, */
  previewLink: string,
  printType: string,
  publishedDate: string,
  /* publisher: string, */
  /* ratingsCount: ratingsCount, */
  /* readingModes: string, */
  shelf: option(string),
  /* subtitle: string, */
  title: string
};


let booktypesSearch = json =>
  Json.Decode.{
    allowAnonLogging: json |> field("allowAnonLogging", bool),
    authors: json |> optional(field("authors", list(string))),
    /* averageRating: json |> field("averageRating", int), */
    canonicalVolumeLink: json |> field("canonicalVolumeLink", string),
    categories: json |> optional(field("categories", list(string))),
    contentVersion: json |> field("contentVersion", string),
    description: json |> optional(field("description", string)),
    id: json |> field("id", string),
    imageLinks: json |> field("imageLinks", imageLinksJson),
    /* industryIdentifiers: list(industryIdentifiers), */
    infoLink: json |> field("infoLink", string),
    language: json |> field("language", string),
    maturityRating: json |> field("maturityRating", string),
    pageCount: json |> optional(field("pageCount", int)),
    /* panelizationSummary: panelizationSummary, */
    previewLink: json |> field("previewLink", string),
    printType: json |> field("printType", string),
    publishedDate: json |> field("publishedDate", string),
    /* publisher: json |> field("publisher", string), */
    /* ratingsCount: ratingsCount, */
    /* readingModes: json |> field("readingModes", string), */
    shelf: json |> optional(field("shelf", string)),
    /* subtitle: json |> field("subtitle", string), */
    title: json |> field("title", string),
  };

let api = "https://reactnd-books-api.udacity.com";

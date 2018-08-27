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

type booksType = {
  allowAnonLogging: bool,
  authors: list(string),
  /* averageRating: int, */
  canonicalVolumeLink: string,
  categories: option(list(string)),
  contentVersion: string,
  description: string,
  id: string,
  imageLinks: imageLinks,
  /* industryIdentifiers: list(industryIdentifiers), */
  infoLink: string,
  language: string,
  maturityRating: string,
  pageCount: int,
  /* panelizationSummary: panelizationSummary, */
  previewLink: string,
  printType: string,
  publishedDate: string,
  /* publisher: string, */
  /* ratingsCount: ratingsCount, */
  /* readingModes: string, */
  shelf: string,
  /* subtitle: string, */
  title: string
};

let imageLinksJson = json =>
  Json.Decode.{
    smallThumbnail: json |> field("smallThumbnail", string),
    /* smallThumbnail: json |> optional(field("smallThumbnail", string)), */
    /* thumbnail: json |> optional(field("smallThumbnail", string)), */
    thumbnail: json |> field("smallThumbnail", string),
  };

let booktypes = json =>
  Json.Decode.{
    allowAnonLogging: json |> field("allowAnonLogging", bool),
    authors: json |> field("authors", list(string)),
    /* averageRating: json |> field("averageRating", int), */
    canonicalVolumeLink: json |> field("canonicalVolumeLink", string),
    categories: json |> optional(field("categories", list(string))),
    contentVersion: json |> field("contentVersion", string),
    description: json |> field("description", string),
    id: json |> field("id", string),
    imageLinks: json |> field("imageLinks", imageLinksJson),
    /* industryIdentifiers: list(industryIdentifiers), */
    infoLink: json |> field("infoLink", string),
    language: json |> field("language", string),
    maturityRating: json |> field("maturityRating", string),
    pageCount: json |> field("pageCount", int),
    /* panelizationSummary: panelizationSummary, */
    previewLink: json |> field("previewLink", string),
    printType: json |> field("printType", string),
    publishedDate: json |> field("publishedDate", string),
    /* publisher: json |> field("publisher", string), */
    /* ratingsCount: ratingsCount, */
    /* readingModes: json |> field("readingModes", string), */
    shelf: json |> field("shelf", string),
    /* subtitle: json |> field("subtitle", string), */
    title: json |> field("title", string),
  };

let api = "https://reactnd-books-api.udacity.com";

#' Compact Language Detector 3
#'
#' The function [detect_language()] is vectorised and guesses the the language of each string
#' in `text` or returns `NA` if the language could not reliably be determined. The function
#' [detect_language_multi()] is not vectorised and detects all languages inside the entire
#' character vector as a whole.
#'
#' @importFrom Rcpp sourceCpp
#' @useDynLib cld3
#' @name cld3
#' @aliases cld3
#' @export
#' @rdname cld3
#' @param text a string with text to classify or a connection to read from
#' @examples # Vectorized best guess
#' text <- c("To be or not to be?", "Ce n'est pas grave.",
#'   "Hij heeft de klok horen luiden maar weet niet waar de klepel hangt.")
#' detect_language(text)
#'
#' # Multiple languages in one text (doesn't seem to work well)
#' detect_language_mixed(text)
detect_language <- function(text){
  if(is.data.frame(text)){
    text <- text$text
    if(!length(text))
      stop("Argument 'text' does not contain a 'text' column.")
  }
  cld3_detect_language(as_string(text))
}

#' @export
#' @aliases detect_language_multi
#' @rdname cld3
#' @param size number of languages to detect
detect_language_mixed <- function(text, size = 3){
  cld3_detect_language_mixed(as_string(text, vectorize = FALSE), size)
}

as_string <- function(text, vectorize = TRUE){
  if(inherits(text, "connection")){
    con <- text
    if(!isOpen(con)){
      on.exit(try(close(con), silent = TRUE))
      open(con)
    }
    text <- readLines(con, warn = FALSE)
  }
  if(!is.character(text) || !length(text))
    stop("Parameter 'text' must be a connection or character vector")
  paste(enc2utf8(text), collapse = if(!vectorize) "\n")
}

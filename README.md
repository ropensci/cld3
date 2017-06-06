# cld3

##### *R Wrapper for Google's Compact Language Detector 3*

[![Build Status](https://travis-ci.org/ropensci/cld3.svg?branch=master)](https://travis-ci.org/ropensci/cld3)
[![AppVeyor Build Status](https://ci.appveyor.com/api/projects/status/github/ropensci/cld3?branch=master&svg=true)](https://ci.appveyor.com/project/jeroen/cld3)
[![Coverage Status](https://codecov.io/github/ropensci/cld3/coverage.svg?branch=master)](https://codecov.io/github/ropensci/cld3?branch=master)
[![CRAN_Status_Badge](http://www.r-pkg.org/badges/version/cld3)](https://cran.r-project.org/package=cld3)
[![CRAN RStudio mirror downloads](http://cranlogs.r-pkg.org/badges/cld3)](https://cran.r-project.org/package=cld3)
[![Github Stars](https://img.shields.io/github/stars/ropensci/cld3.svg?style=social&label=Github)](https://github.com/ropensci/cld3)

> Google's Compact Language Detector 3 is a neural network model for language 
  identification and the successor of CLD2 (available from) CRAN. This version is still
  experimental and uses a novell algorithm with different properties and outcomes. For
  more information see: https://github.com/google/cld3#readme

The function `detect_language()` is vectorised and guesses the the language of each string in text or returns NA if the language could not reliably be determined.

```r
> library(cld3)
> example(cld3)

cld3> # Vectorized best guess
cld3> detect_language(c("To be or not to be?", "Ce n'est pas grave.", "猿も木から落ちる"))
[1] "en" "fr" "ja"
```

The function `detect_language_multi()` is not vectorised and detects all languages inside the entire character vector as a whole.
 
```r

cld3> # Multiple languages in one text
cld3> detect_language_mixed("This piece of text is in English. Този текст е на Български.", size = 3)
  language probability reliable proportion
1       bg   0.9173891     TRUE  0.5853658
2       en   0.9999790     TRUE  0.4146341
3      und   0.0000000    FALSE  0.0000000
```

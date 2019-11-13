# cld3

> R Wrapper for Google's Compact Language Detector 3

[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)
[![Build Status](https://travis-ci.org/ropensci/cld3.svg?branch=master)](https://travis-ci.org/ropensci/cld3)
[![AppVeyor Build Status](https://ci.appveyor.com/api/projects/status/github/ropensci/cld3?branch=master&svg=true)](https://ci.appveyor.com/project/jeroen/cld3)
[![CRAN_Status_Badge](http://www.r-pkg.org/badges/version/cld3)](https://cran.r-project.org/package=cld3)
[![CRAN RStudio mirror downloads](http://cranlogs.r-pkg.org/badges/cld3)](https://cran.r-project.org/package=cld3)


Google's Compact Language Detector 3 is a neural network model for language 
identification and the successor of CLD2 (available from) CRAN. This version is still
experimental and uses a novell algorithm with different properties and outcomes. For
more information see: https://github.com/google/cld3#readme

## Example

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



## Installation

Binary packages for __OS-X__ or __Windows__ can be installed directly from CRAN:

```r
install.packages("cld3")
```

Installation from source on Linux or OSX requires Google's [Protocol Buffers](https://developers.google.com/protocol-buffers/) library. On __Debian or Ubuntu__ install [libprotobuf-dev](https://packages.debian.org/testing/libprotobuf-dev) and [protobuf-compiler](https://packages.debian.org/testing/protobuf-compiler):

```
sudo apt-get install -y libprotobuf-dev protobuf-compiler
```

On __Fedora__ we need [protobuf-devel](https://apps.fedoraproject.org/packages/protobuf-devel):

```
sudo yum install protobuf-devel
````

On __CentOS / RHEL__ we install [protobuf-devel](https://apps.fedoraproject.org/packages/protobuf-devel) via EPEL:

```
sudo yum install epel-release
sudo yum install protobuf-devel
```

On __OS-X__ use [protobuf](https://github.com/Homebrew/homebrew-core/blob/master/Formula/protobuf.rb) from Homebrew:

```
brew install protobuf
```

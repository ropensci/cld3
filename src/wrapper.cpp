#include "libcld3/base.h"
#include "libcld3/nnet_language_identifier.h"

#define STRICT_R_HEADERS
#define R_NO_REMAP
#include <Rcpp.h>
#include <string>

using chrome_lang_id::NNetLanguageIdentifier;

// [[Rcpp::export]]
Rcpp::CharacterVector cld3_detect_language(std::vector<std::string> texts){
  NNetLanguageIdentifier lang_id(0, 1000);
  size_t len = texts.size();
  Rcpp::CharacterVector out(len);
  for (size_t i = 0; i < len; i++) {
    const NNetLanguageIdentifier::Result result = lang_id.FindLanguage(texts[i]);
    if(result.is_reliable)
      out[i] = result.language;
    else
      out[i] = NA_STRING;
  }
  return out;
}

// [[Rcpp::export]]
Rcpp::DataFrame cld3_detect_language_df(std::vector<std::string> texts) {
  // Sets: min_num_bytes and max_num_bytes.
  NNetLanguageIdentifier lang_id(0, 1000);
  size_t len = texts.size();
  Rcpp::CharacterVector language(len);
  Rcpp::NumericVector probability(len);
  Rcpp::LogicalVector reliable(len);
  Rcpp::NumericVector proportion(len);

  for (size_t i = 0; i < len; i++) {
    const NNetLanguageIdentifier::Result result = lang_id.FindLanguage(texts[i]);
    language[i] = result.language;
    probability[i] = result.probability;
    reliable[i] = result.is_reliable;
    proportion[i] = result.proportion;
  }

  return Rcpp::DataFrame::create(
    Rcpp::Named("language") = language,
    Rcpp::Named("probability") = probability,
    Rcpp::Named("reliable") = reliable,
    Rcpp::Named("proportion") = proportion
  );
}

// [[Rcpp::export]]
Rcpp::DataFrame cld3_detect_language_mixed(std::string text, size_t len = 3) {
  // Sets: min_num_bytes and max_num_bytes.
  NNetLanguageIdentifier lang_id(0, text.size());
  const std::vector<NNetLanguageIdentifier::Result> results = lang_id.FindTopNMostFreqLangs(text,  len);
  Rcpp::CharacterVector language(len);
  Rcpp::NumericVector probability(len);
  Rcpp::LogicalVector reliable(len);
  Rcpp::NumericVector proportion(len);
  for (size_t i = 0; i < len; i++) {
    language[i] = results[i].language;
    probability[i] = results[i].probability;
    reliable[i] = results[i].is_reliable;
    proportion[i] = results[i].proportion;
  }
  return Rcpp::DataFrame::create(
    Rcpp::Named("language") = language,
    Rcpp::Named("probability") = probability,
    Rcpp::Named("reliable") = reliable,
    Rcpp::Named("proportion") = proportion,
    Rcpp::Named("stringsAsFactors") = false
  );
}

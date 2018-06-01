/*
  bgmg - tool to calculate log likelihood of BGMG and UGMG mixture models
  Copyright (C) 2018 Oleksandr Frei

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define VERSION "v0.9.0"

#include <stdexcept>
#include "boost/exception/diagnostic_information.hpp"
#include "boost/exception/get_error_info.hpp"

#include <bgmg.h>
#include "bgmg_calculator.h"

static std::string last_error_;
static const char* last_error() { return last_error_.c_str(); }
static void set_last_error(const std::string& error) { last_error_.assign(error); }
const char* bgmg_get_last_error() { return last_error(); }

#define CATCH_EXCEPTIONS                                                       \
catch (const std::runtime_error& e) {                                          \
  set_last_error("runtime_error:  " + std::string(e.what()));                  \
  return -1;                                                                   \
} catch (...) {                                                                \
  set_last_error(boost::current_exception_diagnostic_information());           \
  return -1;                                                                   \
}

int64_t bgmg_set_zvec(int context_id, int trait, int length, float* values) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->set_zvec(trait, length, values);
  } CATCH_EXCEPTIONS;
}

int64_t bgmg_set_nvec(int context_id, int trait, int length, float* values) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->set_nvec(trait, length, values);
  } CATCH_EXCEPTIONS;
}

int64_t bgmg_set_hvec(int context_id, int length, float* values) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->set_hvec(length, values);
  } CATCH_EXCEPTIONS;
}

int64_t bgmg_set_weights(int context_id, int length, float* values) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->set_weights(length, values);
  } CATCH_EXCEPTIONS;
}

int64_t bgmg_set_tag_indices(int context_id, int num_snp, int num_tag, int* tag_indices) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->set_tag_indices(num_snp, num_tag, tag_indices);
  } CATCH_EXCEPTIONS;
}

int64_t bgmg_set_ld_r2_coo(int context_id, int length, int* snp_index, int* tag_index, float* r2) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->set_ld_r2_coo(length, snp_index, tag_index, r2);
  } CATCH_EXCEPTIONS;
}

int64_t bgmg_set_ld_r2_csr(int context_id) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->set_ld_r2_csr();
  } CATCH_EXCEPTIONS;
}

int64_t bgmg_retrieve_tag_r2_sum(int context_id, int component_id, float num_causal, int length, float* buffer) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->retrieve_tag_r2_sum(component_id, num_causal, length, buffer);
  } CATCH_EXCEPTIONS;
}

int64_t bgmg_retrieve_weights(int context_id, int length, float* buffer) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->retrieve_weights(length, buffer);
  } CATCH_EXCEPTIONS;
}

int64_t bgmg_set_option(int context_id, char* option, double value) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->set_option(option, value);
  } CATCH_EXCEPTIONS;
}

double bgmg_calc_univariate_cost(int context_id, double pi_vec, double sig2_zero, double sig2_beta) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->calc_univariate_cost(pi_vec, sig2_zero, sig2_beta);
  } CATCH_EXCEPTIONS;
}

double bgmg_calc_univariate_pdf(int context_id, float pi_vec, float sig2_zero, float sig2_beta, int length, float* zvec, float* pdf) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->calc_univariate_pdf(pi_vec, sig2_zero, sig2_beta, length, zvec, pdf);
  } CATCH_EXCEPTIONS;
}

double bgmg_calc_bivariate_cost(int context_id, int pi_vec_len, float* pi_vec, int sig2_beta_len, float* sig2_beta, float rho_beta, int sig2_zero_len, float* sig2_zero, float rho_zero) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->calc_bivariate_cost(pi_vec_len, pi_vec, sig2_beta_len, sig2_beta, rho_beta, sig2_zero_len, sig2_zero, rho_zero);
  } CATCH_EXCEPTIONS;
}

int64_t bgmg_set_weights_randprune(int context_id, int n, float r2) {
  try {
    set_last_error(std::string());
    return BgmgCalculatorManager::singleton().Get(context_id)->set_weights_randprune(n, r2);
  } CATCH_EXCEPTIONS;
}

int64_t bgmg_dispose(int context_id) {
  try {
    set_last_error(std::string());
    BgmgCalculatorManager::singleton().Erase(context_id);
    return 0;
  } CATCH_EXCEPTIONS;
}

const char* bgmg_status(int context_id) {
  return "";
}
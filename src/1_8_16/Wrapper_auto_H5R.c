
/**************************************************************************
 * 
 * Copyright 2016 Novartis Institutes for BioMedical Research Inc.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *************************************************************************/

#include "Wrapper_auto_H5R.h"
/* H5_DLL herr_t H5Rcreate(void *ref, hid_t loc_id, const char *name, H5R_type_t ref_type, hid_t space_id); */
SEXP R_H5Rcreate(SEXP R_ref, SEXP R_loc_id, SEXP R_name, SEXP R_ref_type, SEXP R_space_id, SEXP _dupl_ref){
  int vars_protected=0;
  if(SEXP_to_logical(_dupl_ref)) {
    R_ref = PROTECT(duplicate(R_ref));
    vars_protected++;
  }
  void* ref;
  if(XLENGTH(R_ref) == 0) {
    ref = NULL;
  }
  else {
    ref = (void *) VOIDPTR(R_ref);
  }
  hid_t loc_id = SEXP_to_longlong(R_loc_id, 0);
  const char* name = CHAR(STRING_ELT(R_name, 0));
  H5R_type_t ref_type = SEXP_to_longlong(R_ref_type, 0);
  hid_t space_id = SEXP_to_longlong(R_space_id, 0);
  herr_t return_val = H5Rcreate(ref, loc_id, name, ref_type, space_id);
  SEXP R_return_val= R_NilValue;
  R_return_val = PROTECT(ScalarInteger64_or_int(return_val));
  vars_protected++;
  SEXP __ret_list;
  PROTECT(__ret_list = allocVector(VECSXP, 2));
  SET_VECTOR_ELT(__ret_list, 0, R_return_val);
  SET_VECTOR_ELT(__ret_list, 1, R_ref);
  SEXP __ret_list_names;
  PROTECT(__ret_list_names = allocVector(STRSXP, 2));
  SET_STRING_ELT(__ret_list_names, 0, mkChar("return_val"));
  SET_STRING_ELT(__ret_list_names, 1, mkChar("ref"));
  SET_NAMES(__ret_list, __ret_list_names);
  vars_protected += 2;
  UNPROTECT(vars_protected);
  return(__ret_list);
}

/* H5_DLL hid_t H5Rdereference(hid_t dataset, H5R_type_t ref_type, const void *ref); */
SEXP R_H5Rdereference(SEXP R_dataset, SEXP R_ref_type, SEXP R_ref){
  int vars_protected=0;
  hid_t dataset = SEXP_to_longlong(R_dataset, 0);
  H5R_type_t ref_type = SEXP_to_longlong(R_ref_type, 0);
  const void* ref;
  if(XLENGTH(R_ref) == 0) {
    ref = NULL;
  }
  else {
    ref = (void *) VOIDPTR(R_ref);
  }
  hid_t return_val = H5Rdereference(dataset, ref_type, ref);
  SEXP R_return_val= R_NilValue;
  R_return_val = PROTECT(ScalarInteger64_or_int(return_val));
  vars_protected++;
  SEXP __ret_list;
  PROTECT(__ret_list = allocVector(VECSXP, 1));
  SET_VECTOR_ELT(__ret_list, 0, R_return_val);
  SEXP __ret_list_names;
  PROTECT(__ret_list_names = allocVector(STRSXP, 1));
  SET_STRING_ELT(__ret_list_names, 0, mkChar("return_val"));
  SET_NAMES(__ret_list, __ret_list_names);
  vars_protected += 2;
  UNPROTECT(vars_protected);
  return(__ret_list);
}

/* H5_DLL ssize_t H5Rget_name(hid_t loc_id, H5R_type_t ref_type, const void *ref, char *name, size_t size); */
SEXP R_H5Rget_name(SEXP R_loc_id, SEXP R_ref_type, SEXP R_ref, SEXP R_name, SEXP R_size){
  int vars_protected=0;
  R_name = PROTECT(duplicate(R_name));
  vars_protected++;
  hid_t loc_id = SEXP_to_longlong(R_loc_id, 0);
  H5R_type_t ref_type = SEXP_to_longlong(R_ref_type, 0);
  const void* ref;
  if(XLENGTH(R_ref) == 0) {
    ref = NULL;
  }
  else {
    ref = (void *) VOIDPTR(R_ref);
  }
  char* name;
  if(XLENGTH(R_name) == 0) {
    name = NULL;
  }
  else {
    name = R_alloc(strlen(CHAR(STRING_ELT(R_name, 0))) + 1, 1);
    strcpy(name, CHAR(STRING_ELT(R_name, 0)));
  }
  size_t size = SEXP_to_longlong(R_size, 0);
  ssize_t return_val = H5Rget_name(loc_id, ref_type, ref, name, size);
  SEXP R_return_val= R_NilValue;
  R_return_val = PROTECT(ScalarInteger64_or_int(return_val));
  vars_protected++;
  if(name==NULL) {
    R_name = PROTECT(NEW_CHARACTER(0));
    vars_protected++;
  }
  else {
    R_name = PROTECT(mkString(name));
    vars_protected++;
  }
  SEXP __ret_list;
  PROTECT(__ret_list = allocVector(VECSXP, 2));
  SET_VECTOR_ELT(__ret_list, 0, R_return_val);
  SET_VECTOR_ELT(__ret_list, 1, R_name);
  SEXP __ret_list_names;
  PROTECT(__ret_list_names = allocVector(STRSXP, 2));
  SET_STRING_ELT(__ret_list_names, 0, mkChar("return_val"));
  SET_STRING_ELT(__ret_list_names, 1, mkChar("name"));
  SET_NAMES(__ret_list, __ret_list_names);
  vars_protected += 2;
  UNPROTECT(vars_protected);
  return(__ret_list);
}

/* H5_DLL herr_t H5Rget_obj_type2(hid_t id, H5R_type_t ref_type, const void *_ref, H5O_type_t *obj_type); */
SEXP R_H5Rget_obj_type2(SEXP R_id, SEXP R_ref_type, SEXP R__ref, SEXP R_obj_type){
  hsize_t size_helper;
  SEXP R_helper = R_NilValue;
  int vars_protected=0;
  R_obj_type = PROTECT(duplicate(R_obj_type));
  vars_protected++;
  hid_t id = SEXP_to_longlong(R_id, 0);
  H5R_type_t ref_type = SEXP_to_longlong(R_ref_type, 0);
  const void* _ref;
  if(XLENGTH(R__ref) == 0) {
    _ref = NULL;
  }
  else {
    _ref = (void *) VOIDPTR(R__ref);
  }
  H5O_type_t* obj_type;
  if(XLENGTH(R_obj_type) == 0) {
    obj_type = NULL;
  }
  else {
    R_helper = PROTECT(RToH5(R_obj_type, h5_datatype[DT_H5O_type_t], XLENGTH(R_obj_type)));
    obj_type= (H5O_type_t*) VOIDPTR(R_helper);
    vars_protected++;
  }
  herr_t return_val = H5Rget_obj_type2(id, ref_type, _ref, obj_type);
  SEXP R_return_val= R_NilValue;
  R_return_val = PROTECT(ScalarInteger64_or_int(return_val));
  vars_protected++;
  size_helper = guess_nelem(R_obj_type, h5_datatype[DT_H5O_type_t]);
  R_obj_type = PROTECT(H5ToR_single_step(obj_type, h5_datatype[DT_H5O_type_t], size_helper, H5TOR_CONV_INT64_NOLOSS));
  vars_protected++;
  SEXP __ret_list;
  PROTECT(__ret_list = allocVector(VECSXP, 2));
  SET_VECTOR_ELT(__ret_list, 0, R_return_val);
  SET_VECTOR_ELT(__ret_list, 1, R_obj_type);
  SEXP __ret_list_names;
  PROTECT(__ret_list_names = allocVector(STRSXP, 2));
  SET_STRING_ELT(__ret_list_names, 0, mkChar("return_val"));
  SET_STRING_ELT(__ret_list_names, 1, mkChar("obj_type"));
  SET_NAMES(__ret_list, __ret_list_names);
  vars_protected += 2;
  UNPROTECT(vars_protected);
  return(__ret_list);
}

/* H5_DLL hid_t H5Rget_region(hid_t dataset, H5R_type_t ref_type, const void *ref); */
SEXP R_H5Rget_region(SEXP R_dataset, SEXP R_ref_type, SEXP R_ref){
  int vars_protected=0;
  hid_t dataset = SEXP_to_longlong(R_dataset, 0);
  H5R_type_t ref_type = SEXP_to_longlong(R_ref_type, 0);
  const void* ref;
  if(XLENGTH(R_ref) == 0) {
    ref = NULL;
  }
  else {
    ref = (void *) VOIDPTR(R_ref);
  }
  hid_t return_val = H5Rget_region(dataset, ref_type, ref);
  SEXP R_return_val= R_NilValue;
  R_return_val = PROTECT(ScalarInteger64_or_int(return_val));
  vars_protected++;
  SEXP __ret_list;
  PROTECT(__ret_list = allocVector(VECSXP, 1));
  SET_VECTOR_ELT(__ret_list, 0, R_return_val);
  SEXP __ret_list_names;
  PROTECT(__ret_list_names = allocVector(STRSXP, 1));
  SET_STRING_ELT(__ret_list_names, 0, mkChar("return_val"));
  SET_NAMES(__ret_list, __ret_list_names);
  vars_protected += 2;
  UNPROTECT(vars_protected);
  return(__ret_list);
}


#include <stdio.h>
#include <string.h>
#include <assert.h>

char *strchr_(const char *cs, const char c){
  while(*cs != c && *cs != '\0'){
    ++cs;
  }
  if(*cs == '\0'){
    return NULL;
  }else{
    return cs;
  }
}

char *strrchr_(const char *cs, const char c){
  char *pstart = cs;
  while(*cs != '\0'){
    ++cs;
  }
  while(*cs != c && cs != pstart){
    --cs;
  }
  if(cs == pstart && *pstart != c){
    return NULL;
  }else{return cs;}
}

size_t strspn_(const char *cs, const char *ct){
  size_t count = 0;
  while(*cs != '\0'){
    if(strchr(ct, *cs) != NULL){
      ++count;
    }else{return count;}
    ++cs;
  }
  return count;
}

size_t  strcspn_(const char *cs, const char *ct){
  size_t count = 0;
    while(*cs != '\0'){
      if(strchr(ct, *cs) == NULL){
        ++count;
      }else{return count;}
      ++cs;
    }
    return count;
}


char *strpbrk_(const char *cs, const char *ct){
  char *pstart = cs;
  while(*ct != '\0'){
    while(*cs != *ct && *cs != '\0'){
      ++cs;
    }
    if(*cs == *ct){
      return cs;
    }else{
      ++ct;
      cs = pstart;
    }
  }
  return cs;
}



char *strstr_(const char *cs, const char *ct){
  const char c = *ct;
  size_t length = strlen(ct);
  while(*cs != '\0'){
    if(c == *cs && strncmp(cs,ct,length) == 0){
      return cs;
    }
    ++cs;
  }
  return NULL;
}

void test_strchr_strstr(const char *s, const char *t, const char c){
  assert(strchr_(s,c) == strchr(s,c));
  assert(strrchr_(s,c) == strrchr(s,c));
  assert(strstr_(s,t) == strstr(s,t));
  printf("Assertions for strchr, strrchr, and strstr passed.\n");
}

void test_strspn(const char *s, const char *t){
  assert(strspn_(s,t) == strspn(s,t));
  assert(strcspn_(s,t) == strcspn(s,t));
  printf("Assertions for strspn and strcspn passed.\n");
}

void test_strpbrk(const char *s, const char *t){
  assert(strpbrk(s,t) == strpbrk_(s,t));
  printf("Assertions for strpbrk passed.\n");
}


int main(){
  char buf1[100] = "supper";
  char buf2[100] = "upper";
  char char1 = 'p';
  char buf3[100] = "superb";
  char buf4[100] = "upsfedex";
  char buf5[100] = "Mister Dursley turned and said, what!?";
  char buf6[100] = "!?,.:;";

  test_strchr_strstr(buf1,buf2, char1);
  test_strspn(buf3,buf4);
  test_strpbrk(buf5,buf6);

  return 0;
}

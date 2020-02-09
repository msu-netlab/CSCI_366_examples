#include <stdio.h>
#include <unistd.h>
#include "yaml-cpp/yaml.h"

//#define BASIC
//#define OPTIONS
#define CONFIG_FILES

int main(int argc, char *argv[]) {
   int aflag = -1;
   int bflag = -1;
   std::string cvalue;

   printf("Hello World!\n");

#ifdef BASIC
   // read command line arguments as strings
   for (int i = 0; i < argc; ++i)
      printf("Argument %d is %s\n", i, argv[i]);

   /**
    * Exercise: parse "main -n1 filename" as in "head -n1 filename"
    */

   /*
    * Conclusions:
    * - Whatever you do, don't write your own parser!
    */
#endif

#ifdef OPTIONS
   // parse command line arguments as options (named arguments)
   int opt;
   // ":" follows an option name to get argument from optarg
   while((opt = getopt(argc, argv, "abc:")) != -1){
      switch(opt){
         case 'a':
            printf("option: %c\n", opt);
            aflag = 1;
            break;
         case 'b':
            printf("option: %c\n", opt);
            bflag = 1;
            break;
         case 'c':
            printf("option %c, value: %s\n", opt, optarg);
            cvalue = optarg;
            break;
         case '?':
            printf("unknown option: %c\n", optopt);
            break;
      }
   }

   printf ("aflag = %d, bflag = %d, cvalue = %s\n",
           aflag, bflag, cvalue.c_str());

   // optind is for the extra arguments that are not parsed
   for(; optind < argc; optind++){
      printf("extra argument: %s\n", argv[optind]);
   }

   /**
    * Conclusions:
    * + good for calling multiple commands with scripts
    * - cumbersome with many options
    */
#endif

#ifdef CONFIG_FILES
   // parse options from a configuration file
   // YAML Ain't Markup Language (or yet another markup language) https://yaml.org/
   YAML::Node config = YAML::LoadFile("config.yaml");

   if(config["a"])
      aflag = config["a"].as<int>();
   if(config["b"])
      bflag = config["b"].as<bool>() == 1;
   if(config["c"])
      cvalue = config["c"].as<std::string>();



   printf ("aflag = %d, bflag = %d, cvalue = %s\n",
           aflag, bflag, cvalue.c_str());
   /**
    * Conclusions:
    * + many configuration file options INI, YAML, TOML, JSON, https://www.hyperrealm.com/libconfig/libconfig.html, http://www.config4star.org/
    * - readability vs features vs correctness: https://github.com/crdoconnor/strictyaml
    * + learn more about YAML here: https://rollout.io/blog/yaml-tutorial-everything-you-need-get-started/
    */
#endif

   return 0;
}

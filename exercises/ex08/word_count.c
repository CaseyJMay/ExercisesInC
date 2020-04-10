#include <stdio.h>
#include <gmodule.h>
#include <glib.h>
#include <stdlib.h>

void hash_up(char *key, int val) {
  g_print("%s: %d\n", key, val);
}

int main() {

  // Make the hashtable we will eventually populate
  GHashTable *ht = g_hash_table_new(g_str_hash, g_str_equal);
  char *buffer = malloc(500*sizeof(char*));

  // open the file
  FILE *text = fopen("PaulJones.txt","rb");
  while (fscanf(text, "%s\n", buffer) != EOF) {
    // checks if key is in the hashtable
    if (g_hash_table_contains(ht,buffer)){
      //replace
      g_hash_table_replace(ht, g_strdup(buffer), g_hash_table_lookup(ht, buffer)+1);
    } else {
      // insert
      g_hash_table_insert(ht, g_strdup(buffer), GINT_TO_POINTER(1));
    }
  }

  // close the file
  fclose(file);
  g_hash_table_foreach(ht, (GHFunc)hash_up, NULL);

}

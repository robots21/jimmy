/*************************************************************************/

typedef struct mrdplot_data
{
  char *filename;
  int total_n_numbers;
  int n_points;
  int n_channels;
  float frequency;
  float *data;
  char **names;
  char **units;
} MRDPLOT_DATA;

/*************************************************************************/

MRDPLOT_DATA *malloc_mrdplot_data( int n_channels, int n_points );
MRDPLOT_DATA *read_mrdplot( char *filename );
void write_mrdplot_file( MRDPLOT_DATA *d );
int find_channel( char *name, MRDPLOT_DATA *d );
char *generate_file_name(char *prefix);
char *last_data();

/*************************************************************************/

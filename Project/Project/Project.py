import pandas as pd

import sqlite3, os, glob


 

#Created dictionary, with elements that needed to be hard coded

sql_type_dict = {

   'media': 'BLOB,',

   'mdftime': 'REAL,',

   'comments': 'TEXT,',

   'VideoOnly_b': 'BLOB,'

   # go back and switch some to int to save some R A M :)

}



       

def sql_string_builder(sql_type_dict, df, report_name):
   sql_query = f'CREATE table if not exists {report_name} ('
   for column in df.columns:
      sql_query += individual_line_genrate(sql_type_dict, column)

   sql_query = sql_query[:len(sql_query) - 1] + ")"
   return sql_query

  
def individual_line_genrate(dict, column_name):
   if column_name in dict:
      return f'\n{column_name} {dict[column_name]},'
   else:
      return f'\n{column_name} real,'

 
def create_insert_query(tablename, row):
    output = ""
    return output


def main():
    conn = sqlite3.connect('test.db')
    cur_obj = conn.cursor()
    os.chdir(r'C:\Users\mahre\Documents\reports')
    for fl in os.listdir():
        if fl[-4:] == '.csv':
            df = pd.read_csv(fl, sep=",", engine = 'python')
            tablename = fl[:len(fl)-4]
            create_table_query = sql_string_builder(sql_type_dict, df, tablename)
            print(create_table_query)
            cur_obj.execute(create_table_query)
            for index, row in df.iterrows():
                insert_query = create_insert_query(tablename, row)
         
        break 
    #connect db
    #cursor_obj.execute(table)
    #Send tables to db
    #send report data to db
    #figure out how to run it 2

main()

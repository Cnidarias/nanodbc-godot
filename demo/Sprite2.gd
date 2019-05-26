extends Sprite

const dbdriver = preload("res://lib/gdnanodbc.gdns")

func _ready():
	var db = dbdriver.new();
	db.connect("Driver=PostgreSQL Unicode;Server=127.0.0.1;Port=5432;Database=test;Uid=postgres;Pwd=postgres;")
	
	if(!db.execute("create table test.test (a integer, b varchar(255))")):
		print("Table already exists or could not be created, check debugger")
	
	var insert = "insert into test.test values(1, 'hello')"
	for c in range(10000):
		db.execute(insert)
	
	var a = db.fetch("select * from test.test")
	for ele in a:
		print(ele)
	pass #
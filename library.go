package main
import(
	"fmt"
	"net/http"
	"github.com/gin-gonic/gin"
	"github.com/jinzhu/gorm"
	_ "github.com/jinzhu/gorm/dialects/mysql"
)

type User struct{
	ID int
	Name string
	Password string
	cookie http.Cookie
}

type Book struct{
	ID int
	Name string
	Borrow bool
	UserId int `gorm:"Default:-1"`
}

func insert(name string,password string){
	u:=User{Name:name,Password:password}
	db.Create(&u)
}

func register(c *gin.Context){
	var user User
	username:=c.PostForm("username")
	password:=c.PostForm("password")
	if username != "" && password != ""{
		user.Name = username
		user.Password = password
		insert(user.Name,user.Password)
		c.String(200,"注册成功")
	}else{
		c.String(200,"用户名与密码不能为空")
	}
}

func queryUser(name string)string{
	var user User
	db.Where("name = ?",name).First(&user)
	return user.Password
}

func login(c *gin.Context){
	username:=c.PostForm("username")
	password:=c.PostForm("password")
	pwd:=queryUser(username)
	if password != "" {
		if pwd == password{
			c.SetCookie("name",username,3600,"/","localhost",false,true)
			c.String(200,"登陆成功")
		}else{
			c.String(200,"密码不正确")
		}
	}else{
		c.String(200,"该用户不存在")
	}
}

func search(c *gin.Context){
	bookname:=c.PostForm("bookname")
	var book Book
	db.Where("name = ?",bookname).Find(&book)
	if book.Name == "" {
		c.String(200,"查无此书")
	}else{
		//res:=gorm.DB.Joins("User").Where("user_id = ?",book.UserID)
		//想实现表连接然而没学会
		c.JSON(200,book)
	}
}

func add(c *gin.Context){
	bookname := c.PostForm("bookname")
	book:=Book{Name:bookname}
	db.Create(&book)
	c.String(200,"添加图书成功")
}

func borrow(c *gin.Context){
	bookname:=c.PostForm("bookname")
	var book Book
	db.Where("name = ?",bookname).Find(&book)//找这本书的信息
	username,err:=c.Cookie("name")//用cookie找人名
	if err == nil{
		var user User
		db.Where("name = ?",username).Find(&user)//找人的信息
		db.Model(&book).Updates(gin.H{
			"Borrow":true,
			"UserId":user.ID,
			})//写进去
		c.String(200,"借阅成功")
	}else{
		c.String(200,"请先重新登陆")
	}
}

func revert(c *gin.Context){
	bookname:=c.PostForm("bookname")
	var book Book
	db.Where("name = ?",bookname).Find(&book)
	username,err:=c.Cookie("name")
	if err == nil{
		var user User
		db.Where("name = ?",username).Find(&user)
		db.Model(&book).Updates(gin.H{
			"Borrow":false,
			"UserId":-1,
		})
		c.String(200,"归还成功")
	}else{
		c.String(200,"请先重新登陆")
	}
}

var db,Err=gorm.Open("mysql","root:yzx999.@/library")
func main(){
	//db,err:=gorm.Open("mysql","root:yzx999.@/library")
	if Err != nil{
		fmt.Printf("init err:%v\n",Err)
		panic(Err)
	}else{
		fmt.Printf("success\n")
	}
	defer db.Close()

	db.AutoMigrate(&User{})
	db.AutoMigrate(&Book{})

	r:=gin.Default()
	r.POST("/register",register)
	r.POST("/login",login)
	r.POST("/search",search)
	r.POST("/add",add)
	r.POST("/borrow",borrow)
	r.POST("/revert",revert)
	r.Run(":114")
}
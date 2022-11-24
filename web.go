package main
import(
	"fmt"
	"net/http"
	"math/rand"
	"strconv"
	"time"
	//"strings"
)

type User struct{
	telephone string
	password string
	name string
	cookie http.Cookie
}

var users = make(map[string] *User)
//用户们的信息（数据库？）
func register(w http.ResponseWriter,r *http.Request){
	var user User
	telephone:=r.FormValue("telephone")
	password:=r.FormValue("password")
	name:=r.FormValue("name")
	len:=len(telephone)
	if len == 11 && password != ""{
		user.telephone = telephone
		user.password = password
		user.name = name
		if name == "" {
			user.name = telephone 
		}
		users[telephone] = &user
		w.Write([]byte("注册成功"))
	}else{
		w.Write([]byte("注册失败，请先检查电话和密码是否输入正确"))
	}
}

func login(w http.ResponseWriter,r *http.Request){
	telephone:=r.FormValue("telephone")
	password:=r.FormValue("password")
	if a,b:=users[telephone]; b {
		if a.password == password{
			value:=strconv.Itoa(rand.Intn(1145))//一个随机数,
			//同时Value是string型，所以要操作一下
			empire:=time.Now().AddDate(0,0,1)
			cookie:=&http.Cookie{
				Name:	telephone,
				Value:	value,
				Expires:empire,
			}
			http.SetCookie(w,cookie)
			a.cookie=*cookie//赋予cookie
			w.Write([]byte("登陆成功"))
		}else{
			w.Write([]byte("密码错误，请重试"))
		}
	}else{
		w.Write([]byte("该用户不存在"))
	}
}

func get_information(w http.ResponseWriter,r *http.Request){
	//var tele string 
	flag:=false
	for tele,user:=range users{
		cookie,err:=r.Cookie(tele)
		if err == nil && user.cookie.Value==cookie.Value {
			flag=true
			fmt.Fprintf(w,"查看成功\n您的电话是:%s\n您的名字是%s\n",user.telephone,user.name)
		}
	}
	if !flag {
		w.Write([]byte("请重新登录"))
	}
}

func change_information(w http.ResponseWriter,r *http.Request){
	flag:=false
	newpassword:=r.FormValue("password")
	newname:=r.FormValue("name")
	for tele,user:=range users{
		cookie,err:=r.Cookie(tele)
		if err == nil && user.cookie.Value==cookie.Value{
			flag=true
			if newname != ""{
				user.name=newname
			}
			if newpassword != ""{
				user.password=newpassword
			}
			w.Write([]byte("修改成功"))
		}
	}
	if !flag {
		w.Write([]byte("请重新登录"))
	}
}

func main(){
	fmt.Println("running…………")//开跑

	mux:= http.NewServeMux()
	server:=&http.Server{
		Addr:		":114",
		Handler:	mux,
	}//多路复用器

	mux.HandleFunc("/register",register)//注册
	mux.HandleFunc("/login",login)//登录
	mux.HandleFunc("/get_information",get_information)
	mux.HandleFunc("/change_information",change_information)

	server.ListenAndServe()//监听
}
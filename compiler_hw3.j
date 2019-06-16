.class public compiler_hw3
.super java/lang/Object
.field public static a I = 0
.field public static b F = 0.030000
.field public static isStart Z = 1
.field public static s Ljava/lang/String; = "gg"
.field public static f I = 5
.field public static ssss Ljava/lang/String; = "\0"
.method public static add([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 0.300000
	f2i
	istore 2
	ldc 0
	istore 3
	ldc "Hello!"
	astore 4
	return
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc "hahaha"
	astore 0
	getstatic compiler_hw3/s Ljava/lang/String;
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 0
	istore 1
	ldc "\0"
	astore 2
	getstatic compiler_hw3/b F
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	return
.end method

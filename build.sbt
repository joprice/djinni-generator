import sbtassembly.AssemblyPlugin.defaultUniversalScript

ThisBuild / scalaVersion := "2.12.13"
ThisBuild / organization := "com.github.cross-language-cpp"

lazy val djinni = (project in file("."))
  .enablePlugins(GraalVMNativeImagePlugin)
  .configs(IntegrationTest)
  .settings(
    name := "djinni",
    Defaults.itSettings,
    libraryDependencies += "org.scalatest" %% "scalatest" % "3.0.5" % "it",
    libraryDependencies += "org.scala-lang.modules" %% "scala-parser-combinators" % "1.1.2",
    libraryDependencies += "org.yaml" % "snakeyaml" % "1.26",
    libraryDependencies += "com.github.scopt" %% "scopt" % "3.7.1",
    assemblyOutputPath in assembly := { file("target/bin") / (assemblyJarName in assembly).value },
    assemblyJarName in assembly := s"${name.value}",
    assemblyOption in assembly := (assemblyOption in assembly).value.copy(prependShellScript = Some(defaultUniversalScript(shebang = false))),
    test in assembly := {},
    graalVMNativeImageGraalVersion := None,
    graalVMNativeImageCommand :=
      sys.env.get("GRAAL_NATIVE_IMAGE")
        .getOrElse(graalVMNativeImageCommand.value),
    graalVMNativeImageOptions ++= Seq(
      "-H:+AddAllCharsets",
      "--no-fallback",
      "-H:+ReportExceptionStackTraces",
      "-H:EnableURLProtocols=http,https",
      "--initialize-at-build-time",
      "--initialize-at-build-time=scala.runtime.Statics$VM",
      "--allow-incomplete-classpath"
    ) ++ {
      if (scala.util.Properties.isMac)
        Seq.empty
      else
        Seq("--static")
    },
  )
